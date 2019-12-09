#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll d,i,j,n,k,l;
        
        string x,s;
        
        cin>>d;
        set<string>se;
        
        f(i,0,d){
            cin>>x;
            se.insert(x);
        }
        
        set<string>::iterator it;
        
        // for(it=se.begin();it!=se.end();it++)
        //     cout<<*it<<" ";
            
        // cout<<endl;
        cin>>s;
        n=s.size();
        ll dp[n][n];
        
        memset(dp,0,sizeof(dp));
        
        f(i,0,n){
            if(se.find(s.substr(i,1))!=se.end()){
                //cout<<"hi";
                dp[i][i]=1;
            }
        }
        
        for(l=2;l<=n;l++){
            for(i=0;i<=n-l;i++){
                j = i+l-1;
                
                if(se.find(s.substr(i,l))!=se.end())
                    dp[i][j]=1;
                else{
                    for(k=i;k<j;k++)
                        dp[i][j] = dp[i][j] || (dp[i][k] && dp[k+1][j]);
                }
            }
        }
        
        // f(i,0,n){
        //     f(j,0,n){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        cout<<dp[0][n-1]<<endl;
    }
}
