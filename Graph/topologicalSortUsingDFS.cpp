void func(int V,vector<int> adj[],int *arr,int x,int visited[],int &k ){
    
    int i;
    visited[x]=1;
    for(i=0;i<adj[x].size();i++){
        if(visited[adj[x][i]]==0){
            func(V,adj,arr,adj[x][i],visited,k);
        }
    }
    arr[k]=x;
    k--;
}
int* topoSort(int V, vector<int> adj[])
{
    int *arr;
    arr = new int[V];
    //int arr* = (int*)malloc(sizeof(int));
    stack<int>st;
    int visited[V];
    int i,k=V-1;
    for(i=0;i<V;i++){
        visited[i] =0;
    }
    for(i=0;i<V;i++){
        if(visited[i]==0)
             func(V,adj,arr,0,visited,k);
    }
   
  
    return arr;
}
