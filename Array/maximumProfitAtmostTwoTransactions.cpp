//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
#define inf 2e18
  
int main(){
    
    ll n,i,max_price,min_price;
    cin>>n;
    ll price[n];
    ll profit[n];
    f(i,0,n){
         cin>>price[i]; profit[i]=0;
    }
   
    max_price=price[n-1];
    for(i=n-2;i>=0;i--){
        if(price[i]>max_price)
            max_price=price[i];
        profit[i]=max(profit[i+1],max_price-profit[i]);
    }
    min_price=price[0];
    for(i=1;i<n;i++){
        if(price[i]<min_price){
            min_price = price[i];
        }
        profit[i]=max(profit[i-1],profit[i]+price[i]-min_price);
    }

  cout<<profit[n-1]<<endl;

}
