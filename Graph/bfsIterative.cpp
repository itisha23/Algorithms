#include<bits/stdc++.h>
using namespace std;
bool visited[20];
vector<int>vec[20];
void bfs_iterative(int a);
int main()
{
    int x,y,nodes,edges;

    cout<<"Enter number of nodes and edges\n";
    cin>>nodes>>edges;
    cout<<"enter edges\n";
    for(int i=1;i<=edges;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);//undirected graph
    }
    for(int i=0;i<nodes;i++)
    {
        cout<<"adjacency list of node"<<i<<" :";
        for(int j=0;j<vec[i].size();j++)
        {
            if(j==vec[i].size()-1)
                cout<<vec[i][j];
            else
                cout<<vec[i][j]<<"->";
        }
        cout<<endl;
    }int connected_components=0;
    for(int i=0;i<nodes;i++)
    {
        if(visited[i]==false)
        {bfs_iterative(i);
        connected_components++;}
    }
cout<<endl<<"total connected components are "<<connected_components;
}

void bfs_iterative(int a)
{
     int t;
    queue<int> q;
     q.push(a);
    visited[a]=true;
    while(q.size()!=0)
   {
    t=q.front();
    q.pop();
    cout<<t<<" ";
    for(int i=0;i<vec[t].size();i++)
    {
        if(visited[vec[t][i]]==false)
        {
            q.push(vec[t][i]);
            visited[vec[t][i]]=true;
        }
    }
   }
}
