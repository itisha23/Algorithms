#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        ll i,ans=s.size(),len=0,count=0,low,x;
        int hash[26]={0};
        f(i,0,s.size()){
            if(hash[s[i]-'a']==0)
                len++;
            hash[s[i]-'a']++;
            
        }
       // cout<<len<<endl;
        int arr[26]={0};
        low=0;
        f(i,0,s.size()){
            if(arr[s[i]-'a']==0)
                count++;
            arr[s[i]-'a']++;
            if(count==len){
                while(arr[s[low]-'a']>1){
                     arr[s[low]-'a']--;
                    low++;
                   
                }
                x = i-low+1;
                ans = min(ans,x);
            }
        }
        cout<<ans<<endl;
    }
}
