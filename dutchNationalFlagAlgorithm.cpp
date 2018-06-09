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

void sort012(ll arr[], ll  arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    while (mid <= hi)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[lo++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid],arr[hi--]);
            break;
        }
    }
}

int main()
{
    ll n,i;
    cin>>n;
    ll arr[n];
    f(i,0,n)
      cin>>arr[i];
    sort012(arr, n);
    f(i,0,n)
      cout<<arr[i]<<"  ";
    cout<<endl;

    
}


