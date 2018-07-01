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

void sort012 (vector<int> &vec) {
     int n=vec.size(),i=0,j=0,k=n-1;
     while(j<n && k>=j)
     {
         if(vec[j]==1)
         {
             j++;
             continue;
         }
         else if(vec[j]==0)
         {
             swap(vec[i],vec[j]);
             i++;
             j++;
         }
         else
         {
             swap(vec[j],vec[k]);
             k--;
         }
     }
     

}

int main()
{
    ll n,i;
    cin>>n;
    vector<int>vec(n);
    ll arr[n];
    f(i,0,n)
      cin>>vec[i];
    sort012(vec, n);
    f(i,0,n)
      cout<<vec[i]<<"  ";
    cout<<endl;

    
}


