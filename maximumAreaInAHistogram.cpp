#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 2e18
#define pb push_back
#define fi first
#define se second

typedef int l;
typedef unsigned int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;


int main()
{

  ll t;
  cin>>t;
  while(t--)
  {
      ll n,i,prev,ans=INT_MIN,area;
      cin>>n;
      ll arr[n];
      f(i,0,n)
      cin>>arr[i];
      stack<ll>st;
      f(i,0,n)
      {
          if(st.size()==0)
          {
              st.push(i);
          }
          else
          {
              if(arr[i]>=arr[st.top()])
              st.push(i);
              else
              {
                  while(st.size()!=0 && arr[i]<arr[st.top()])
                  {
                      prev=st.top();
                      st.pop();
                      if(st.size()!=0)
                      area=arr[prev]*(i-st.top()-1);
                      else
                      area=arr[prev]*i;
                      ans=max(ans,area);
                  }
                 st.push(i);
              }
          }
      }
     while(st.size()!=0)
     {
           prev=st.top();
           st.pop();
           if(st.size()!=0)
           area=arr[prev]*(i-st.top()-1);
           else
           area=arr[prev]*i;
           ans=max(ans,area);
     }
      cout<<ans<<endl;
  }

}


