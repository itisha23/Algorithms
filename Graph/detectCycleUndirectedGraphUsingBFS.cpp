/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*/
/*You are required to complete this method*/
void bfs(int i, int visited[],queue<pair<int,int> >q,list<int>*adj,int &flag)
{
    int a,parent;
    q.push(make_pair(i,-1));
    visited[i]=1;
    while(q.empty()!=1)
    {
        a=q.front().first;
        parent=q.front().second;
        q.pop();
       // cout<<a<<" "<<parent<<endl;
        list<int>::iterator it;
        for(it=adj[a].begin();it!=adj[a].end();it++)
        {
            if(visited[*it]==0)
            {
                q.push(make_pair(*it,a));
                visited[*it]=1;
            }
            else
            {
                if(*it!=parent)
                {
                   // cout<<*it<<" "<<a<<" "<<parent<<endl;
                    flag=1;break;
                }
                
            }
        }
    }
}
bool Graph :: isCyclic()
{
    queue<pair<int,int> >q;
    int visited[V],i,flag=0;
    for(i=0;i<V;i++)
      visited[i]=0;
    for(i=0;i<V;i++)
    {
        if(visited[i]==0)
        {
            bfs(i,visited,q,adj,flag);
            if(flag)
            return true;
        }
        
    }
    return false;
}
