void dfs(int i,int c,int visited[],int color[],int G[][MAX],int &flag,int V)
{
    //cout<<"*****"<<i<<endl;
    int j;
    visited[i]=1;
    color[i]=c;
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1)
        {
          //  cout<<"&&&"<<i<<" "<<G[i][j]<<endl;
            if(visited[j]==0)
             dfs(j,c*-1,visited,color,G,flag,V);
            else if(visited[j]==1 && color[j]==c)
            {
               // cout<<i<<" "<<j<<" "<<c<<endl;
                flag=1;
                break;
            }
        }
    }
}

bool isBipartite(int G[][MAX],int V)
{
     int i,flag=0;
    int visited[V],color[V];
    for(int i=0;i<V;i++)
      visited[i]=0;
    for(int i=0;i<V;i++)
       color[i]=0;
    for(i=0;i<V;i++)
    {
        if(visited[i]==0)
        {
            dfs(i,1,visited,color,G,flag,V);
            if(flag)
             return false;
        }
    }
    return true; 
}
