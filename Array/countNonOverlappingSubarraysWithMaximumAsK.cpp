#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,count,k,ans,flag;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        cin>>k;
        count =0; ans =0; flag=0;
        f(i,0,n){
            if(arr[i]<k){
                count++;
            }
            else if(arr[i]==k){
                count++;
                flag=1;
            }else{
                if(flag && count){
                    ans+= count;
                }
                flag=0;
                count=0;
            }
        }
        if(flag && count){
            ans+= count;
        }
        
        cout<<ans<<endl;
    }
}