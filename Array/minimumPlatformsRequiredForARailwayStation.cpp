//https://practice.geeksforgeeks.org/problems/minimum-platforms/0

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,x,count=0,ans=0;
        cin>>n;
        vector<pair<ll,char> >vec;
        for(i=0;i<n;i++){
            cin>>x;
            vec.push_back(make_pair(x,'a'));
        }
        for(i=0;i<n;i++){
            cin>>x;
            vec.push_back(make_pair(x,'d'));
        }
        sort(vec.begin(),vec.end());
        for(i=0;i<2*n;i++){
            if(vec[i].second =='a')
            {
                count++;
                ans=max(ans,count);
            }
            else
                count--;
        }
        cout<<ans<<endl;
    }
}
