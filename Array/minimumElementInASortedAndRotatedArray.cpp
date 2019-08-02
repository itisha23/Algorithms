#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    
    ll t;
    cin>>t;
    while(t--){
        ll n,i,low,high,mid;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        low=0;high=n-1;
        while(low<=high){
            if(low==high){
                cout<<arr[low]<<endl;
                break;
            }
            else if((high-low)==1){
                if(arr[low]<arr[high])
                 cout<<arr[low]<<endl;
                else
                 cout<<arr[high]<<endl;
                break;
            }
            else{
                mid=(low+high)/2;
                if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
                    cout<<arr[mid]<<endl;
                    break;
                }
                else if(arr[mid]>arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
    }
}
