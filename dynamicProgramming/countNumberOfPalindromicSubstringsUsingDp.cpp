#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll m=s.size(),i,j,l;
        int dp[m][m];
        
        set<string>se;
        
        memset(dp,0,sizeof(dp));
        
        for(i=0;i<m;i++)
        {
             dp[i][i]=1;se.insert(s.substr(i,1));   
        }
     
         
        
        
        for(l=2;l<=m;l++)
        {
            for(i=0;i<=m-l;i++)
            {
                j=i+l-1;
                if(l==2)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=1; 
                        se.insert(s.substr(i,l));
                    }
                    
                }
                else
                {
                 //   if(i==2 && j==4)
                   // cout<<dp[i-1][j-1]<<endl;
                    
                    if(s[i]==s[j] &&dp[i+1][j-1])
                    {
                              dp[i][j]=1;
                              se.insert(s.substr(i,l));
                    
                    }
              
                    
                }
            }
            
        }
        /*set<string>::iterator it;
        for(it=se.begin();it!=se.end();it++)
        cout<<*it<<endl;*/
        cout<<se.size()<<endl;
    }
}
