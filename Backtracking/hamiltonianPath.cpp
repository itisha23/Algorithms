#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

void func(int v,vector<int>vec[],int visited[], int &flag, int n){
    
    int i;
    for(i=1;i<=n ;i++){
        if(visited[i]==0)
        break;
    }
    if(i==n+1){
        flag=1;
        return;
    }
    
    for(i=0;i<vec[v].size();i++){
        if(visited[vec[v][i]]==0){
            visited[vec[v][i]]=1;
            func(vec[v][i], vec, visited, flag, n);
            visited[vec[v][i]]=0;
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        int n,m,i,x,y,flag;
        cin>>n>>m;
        vector<int>vec[n+1];
        
        for(i=1;i<=m;i++){
            cin>>x>>y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        
        int visited[n+1];
        
        for(i=1;i<=n;i++){
            memset(visited,0,sizeof(visited)); 
            flag=0;
            visited[i]=1;
            func(i,vec,visited,flag,n);
            if(flag){
                break;
            }
        }
        if(flag){
            cout<<1<<endl;
        }
        else
            cout<<0<<endl;
    }
}
