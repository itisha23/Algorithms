//Method 2: Using sorting

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b ;i++) 
int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n, i, sum1=0, sum2=0, ans = -1, j, m;
        cin>>n>>m;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        ll brr[m];
        f(i,0,m)
            cin>>brr[i];

        f(i,0,n)
            sum1+= arr[i];
        f(i,0,m)
            sum2+= brr[i];

        if(sum1 == sum2) {
            ans = -1;
        } else {
                if(sum1 < sum2) {
                    unordered_set<int>se;
                    f(i,0,n)
                        se.insert(arr[i]);
                    f(i,0,m) {
                        if(se.find(sum2 - brr[i] -sum2) != se.end()) {
                            ans = 1;
                            break;
                        }
                    }
                } else {
                    unordered_set<int>se;
                    f(i,0,m)
                        se.insert(brr[i]);
                    f(i,0,n) {
                        if(se.find(sum1 - arr[i] - sum1) != se.end()){
                            ans = 1;
                            break;
                        }
                    } 
                }
        }
        cout<<ans<<endl;
    }
}