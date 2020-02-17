// https://www.geeksforgeeks.org/trapping-rain-water/

using namespace std;
#include<bits/stdc++.h>
#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
#define se second

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
   ll t;
   t=1;
   cin>>t;
   while(t--)
   {
      ll n,i,sum=0,j,left_max, right_max;  
      cin>>n;
      ll arr[n];
      f(i,0,n)
      cin>>arr[i];

     
    left_max = arr[0];
    right_max = arr[n-1];

    i=1; j=n-2;
    while(i<=j) {

        left_max = max(arr[i], left_max);
        right_max = max(arr[j], right_max);

        if(left_max < right_max){
            sum= sum+ left_max -arr[i];
            i++;
        } else {
            sum= sum+right_max - arr[j];
            j--;
        }
    }
    cout<<sum<<endl;
   }
  
    
}


