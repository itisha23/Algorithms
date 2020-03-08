#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b; i++)
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n, low, high, ans, i, mid;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        
        low = 0;
        high = n-1;
        
        while(low<=high) {
            if(low == high || (high-low == 1)){
                
                if(low-1>=0 && (arr[low] == arr[low-1])){
                    ans = arr[high];
                } else{
                    ans = arr[low];
                }
                break;
            }
            
            mid = (low + high)/2;
            
            //cout<<mid<<endl;
            if((arr[mid] == arr[mid+1] && mid %2 ==1) || ((mid-1) %2==1 && arr[mid] == arr[mid-1])){
                high = mid-1;
                //cout<<high<<endl;
            }
            else if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
                ans = arr[mid];
                break;
                
            } else {
                low = mid+1;
            }
        }
        cout<<ans<<endl;
    }
}