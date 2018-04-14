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


void constructSegmentTree(ll arr[],ll tree[],ll ss,ll se,ll si)
{
	ll mid;
	if(ss==se)
      tree[si]=ss;
    else
    {
    	mid=(ss+se)/2;
    	constructSegmentTree(arr,tree,ss,mid,2*si+1);
    	constructSegmentTree(arr,tree,mid+1,se,2*si+2);
    	if(arr[tree[2*si+1]]>arr[tree[2*si+2]])
    		tree[si]=tree[2*si+2];
    	else
    		tree[si]=tree[2*si+1];
    }

}

ll getMinIndex(ll arr[],ll tree[],ll ss,ll se,ll qs, ll qe,ll si)
{
	
	if(qs<=ss && qe>=se)
		return tree[si];
	ll mid=(ss+se)/2;
	if(qs>se|| qe<ss)
		return -1;
	ll ind1=getMinIndex(arr,tree,ss,mid,qs,qe,2*si+1);
	ll ind2=getMinIndex(arr,tree,mid+1,se,qs,qe,2*si+2);
	if(ind1==-1)
		return ind2;
	else if(ind2==-1)
		return ind1;

	else if(arr[ind1]<arr[ind2])
		return ind1;
	else
		return ind2;
}
ll func(ll arr[],ll tree[],ll i,ll n,ll ss,ll se, ll si)
{
	if(ss>se)
		return INT_MIN;
	ll min_index=getMinIndex(arr,tree,0,n,ss,se,0);
	
    ll area1=arr[min_index]*(se-ss+1);
  
    ll area2=func(arr,tree,0,n,ss,min_index-1,0);
    ll area3=func(arr,tree,0,n,min_index+1,se,0);
    return max(area1,max(area2,area3));
}
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
   	ll n,i,height,max_size,area;
   	cin>>n;
   	ll arr[n];
   	f(i,0,n)
   	cin>>arr[i];
   	height=(ll)(ceil(log2(n)));
   	max_size=2*(ll)(pow(2,height))-1;
   	ll tree[max_size];
   	constructSegmentTree(arr,tree,0,n-1,0);
   	area=func(arr,tree,0,n-1,0,n-1,0);
    cout<<area<<endl;
   }

}


