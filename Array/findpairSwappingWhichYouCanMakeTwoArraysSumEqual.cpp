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
            sort(arr, arr+n);
            sort(brr, brr+m);

            if(sum1 < sum2) {
                j = m-1;
                i=0;

                while( i<n && j>=0 ) {
                    
                    if(sum2 - brr[j] + arr[i] == sum1 -arr[i]+brr[j]){
                        ans  = 1;
                        break;
                        
                    } else if(sum2 - brr[j] + arr[i] < sum1 -arr[i]+brr[j]) {
                        j--;
                    } else{
                        i++;
                    }
                }
            } else if(sum2 < sum1) {
                
                j = n-1;
                i=0;

                while(i<m && j>=0) {
                  
                    if(sum1 - arr[j] + brr[i] == sum2 - brr[i] + arr[j]) {
                        ans = 1;
                        break;
                    } else if(sum1 - arr[j] + brr[i] < sum2 - brr[i] + arr[j]) {
                        j--;
                    } else{
                        i++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}