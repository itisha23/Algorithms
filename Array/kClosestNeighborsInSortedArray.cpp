#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        
        ll n,k,x,count,i,j,low,high,upper=-1,mid,diff1,diff2;
        cin>>n;
        ll arr[n];
        f(i,0,n)
            cin>>arr[i];
        cin>>k>>x;
        low=0;
        high=n-1;
        while(low<=high){
            mid=(low+high)/2;
            
            if(arr[mid]==x && (mid+1<n && arr[mid+1]!=x)||(mid+1==n) ){
                upper=mid+1;
                break;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(upper==-1)
            upper=low;
            
        count=0;
        i=upper-1;
        j=upper;
       // cout<<upper<<endl;
       
       
        while(count<k && i>=0 && j<n){
            
            if(arr[i]==x){
                i--;continue;
            }
            if(arr[j]==x){
                j++;continue;
            }
            i--;
            j++;
            count+=2;
        }
        
        while(count<k && i<0 && j<n){
              if(arr[j]==x){
                j++;continue;
            }
            j++;
            count++;
        }
        
        while(count<k && j==n && i>=0){
              if(arr[i]==x){
                i--;continue;
            }
            i--;
            count++;
        }
        
        i=i+1; count=0;
        while(count<k && i<n){
            if(arr[i]==x){
                i++; continue;
            }
           
            cout<<arr[i]<<" ";
            i++;
            count++;
        }
        cout<<endl;
    }
}
