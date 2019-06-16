int  visited[50][50];
int m,n;

void dfs(int arr[MAX][MAX],int  i,int  j)
{
	visited[i][j]=1;
	if( j+1<n && arr[i][j+1]==1 && visited[i][j+1]==0)
		dfs(arr,i,j+1);

	if(j-1>=0 && arr[i][j-1]==1 && visited[i][j-1]==0)
		dfs(arr,i,j-1);

	if(i-1>=0 && j-1>=0 && arr[i-1][j-1]==1 && visited[i-1][j-1]==0)
		dfs(arr,i-1,j-1);

	if(i-1>=0 && j+1<n && arr[i-1][j+1]==1 && visited[i-1][j+1]==0)
		dfs(arr,i-1,j+1);

	if(i-1>=0 && arr[i-1][j]==1 && visited[i-1][j]==0)
		dfs(arr,i-1,j);

	if(i+1<m && j-1>=0 && arr[i+1][j-1]==1 && visited[i+1][j-1]==0)
		dfs(arr,i+1,j-1);

	if(i+1 <m && arr[i+1][j]==1 && visited[i+1][j]==0)
		dfs(arr,i+1,j);

	if(i+1<m && j+1<n && arr[i+1][j+1]==1 && visited[i+1][j+1]==0)
		dfs(arr,i+1,j+1);

	

}

int findIslands(int arr[MAX][MAX], int M, int N)
{
   m=M;
   n=N;
   int i,j,cc=0;
   for(i=0;i<m;i++)
     for(j=0;j<n;j++)
          visited[i][j]=0; 	
          
   for(i=0;i<m;i++)
     for(j=0;j<n;j++)
   	   if(arr[i][j] && visited[i][j]==0)
   	   		{
   	   			dfs(arr,i,j);
   	   			cc++;
   	   		}
   	
   	  return cc;
}
