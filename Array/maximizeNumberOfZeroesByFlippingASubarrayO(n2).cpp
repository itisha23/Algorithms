#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
typedef long long int ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,j,max_diff,count0,count1,orz;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        max_diff =0;orz=0;
        f(i,0,n){
            if(arr[i]==0)
                orz++;
            count0=0,count1=0;
            f(j,i,n){
                if(arr[j]==0)
                    count0++;
                else
                    count1++;
                max_diff = max(max_diff,count1-count0);
            }
        }
        cout<<orz+max_diff<<endl;
    }
}
