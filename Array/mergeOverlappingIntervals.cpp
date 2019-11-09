//https://practice.geeksforgeeks.org/problems/overlapping-intervals/0

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,i,low,high,x,y;
        cin>>n;
        vector<pair<ll,ll> >vec;
        f(i,0,n)
            {
                cin>>x>>y;
                vec.push_back(make_pair(x,y));
            };
        sort(vec.begin(),vec.end());
        low = vec[0].first; high = vec[0].second;
        f(i,1,n){
            if(vec[i].first > high ){
                // new interval
                cout<<low<<" "<<high<<" ";
                low = vec[i].first; high = vec[i].second;
            }
            else{
                //merge
                high = max(high,vec[i].second);
            }
        }
        cout<<low<<" "<<high<<" ";
        cout<<endl;
    }
}