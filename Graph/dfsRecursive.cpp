#include<bits/stdc++.h>
using namespace std;

int count1=0,nodes;

void dfs_recursive(int s);
vector<int>vec[20];
bool visited[20];
int main()
{
    int x,y,edges;int connected_components=0,v1,v2,flag=0;
    for(int i=0;i<20;i++)
    visited[i]=false;
    cout<<"Enter number of nodes and edges\n";
    cin>>nodes>>edges;
    cout<<"enter edges\n";int i;
    for( i=1;i<=edges;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
    }
    for( i=0;i<nodes;i++)
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
    }
  
   

    for(i=0;i<nodes;i++)
    {
        if(visited[i]==false)
       {
        dfs_recursive(i);
        connected_components ++;
        }
      
    }
 cout<<endl<<connected_components;

  

}
void dfs_recursive(int s)
{
    visited[s]=true;
    cout<<s<<" ";
   for(int i=0;i<vec[s].size();i++)
    {
        if(visited[vec[s][i]]==false)
            dfs_recursive(vec[s][i]);
    }

}
