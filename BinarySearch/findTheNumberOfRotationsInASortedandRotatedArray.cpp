#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,i,low,high,mid,pos;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
            
        low = 0;
        high = n-1;
        while(low<=high) {
            if(low == high){
                pos = low;
                break;
            } else if(high-low == 1){
                if(arr[low]<arr[high]){
                   pos = low;
                }
                    
                else{
                    pos = high;
                }
                   
                    break;
            } else {
                mid = (low+high)/2;
                if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
                {
                    pos = mid;
                    break;
                } else if(arr[mid] > arr[high]){
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        cout<<pos<<endl;
    }
}

//The above method works well wih dulpicates, If duplicates are present, then the worst time complexity will be O(nlogn) only
