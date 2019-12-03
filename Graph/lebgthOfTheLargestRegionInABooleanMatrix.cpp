using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll m,n,count,ans=0,i,j,x,y;
        cin>>m>>n;
        ll mat[m][n];
        f(i,0,m){
            f(j,0,n)
                cin>>mat[i][j];
        }
        queue<pair<ll,ll> >q;
        ll visited[m][n];
        memset(visited,0,sizeof(visited));
        pair<ll,ll>p;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(visited[i][j]==0 && mat[i][j]==1){
                    q.push(make_pair(i,j));
                    visited[i][j]=1;
                    count=0;
                    while(!q.empty()){
                        p=q.front();
                        q.pop();
                        count++;
                        
                        x=p.first; y=p.second;
                        if(x-1>=0 && visited[x-1][y]==0 && mat[x-1][y]==1){
                            q.push(make_pair(x-1,y));
                            visited[x-1][y]=1;
                        }
                        else if(x+1<m && visited[x+1][y]==0 && mat[x+1][y]==1){
                            q.push(make_pair(x+1,y));
                            visited[x+1][y]=1;
                        }
                        else if(y-1>=0 && visited[x][y-1]==0 && mat[x][y-1]==1){
                            q.push(make_pair(x,y-1));
                            visited[x][y-1]=1;
                        }
                        else if(y+1<n && visited[x][y+1]==0 && mat[x][y+1]==1){
                            q.push(make_pair(x,y+1));
                            visited[x][y+1]=1;
                        }
                        else if(x-1>=0 && y-1>=0 && visited[x-1][y-1]==0 && mat[x-1][y-1]==1){
                            q.push(make_pair(x-1,y-1));
                            visited[x-1][y-1]=1;
                        }
                         else if(x-1>=0 && y+1<n && visited[x-1][y+1]==0 && mat[x-1][y+1]==1){
                            q.push(make_pair(x-1,y+1));
                            visited[x-1][y+1]=1;
                        }
                         else if(x+1<m && y-1>=0 && visited[x+1][y-1]==0 && mat[x+1][y-1]==1){
                            q.push(make_pair(x+1,y-1));
                            visited[x+1][y-1]=1;
                        }
                         else if(x+1<m && y+1<n && visited[x+1][y+1]==0 && mat[x+1][y+1]==1){
                            q.push(make_pair(x+1,y+1));
                            visited[x+1][y+1]=1;
                        }
                        
                    }
                    ans=max(ans,count);
                }
            }
        }
        cout<<ans<<endl;
    }
}
