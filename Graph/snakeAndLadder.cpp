//Notice how we take inputs

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,x,y,count,v,pos;
        cin>>n;
        ll moves[31]={0};
        f(i,0,n){
            cin>>x>>y;
            moves[x]=y;
        }
        
        ll visited[31]={0};
        queue<pair<ll,ll> >q;
        q.push(make_pair(1,0));
        pair<ll,ll>p;
        visited[1]=1;
        while(!q.empty()){
            
            p=q.front();
            q.pop();
            
            v=p.first;
            count=p.second;
            
            if(v == 30){
                cout<<count<<endl;
                break;
            }
            
            for(i=1;i<=6;i++){
                pos = v+i;
                if(pos<=30){
                    if(moves[pos]!=0){
                        if(visited[moves[pos]]==0){
                            q.push(make_pair(moves[pos],count+1));
                            visited[moves[pos]]=1;
                        }
                    }
                    else{
                         if(visited[pos]==0){
                            q.push(make_pair(pos,count+1));
                            visited[pos]=1;
                        }
                    }
                }
            }
        }
    }
}
