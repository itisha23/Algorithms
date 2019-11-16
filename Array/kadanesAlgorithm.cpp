
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
         ll n,i,max_so_far,sum=0;
 cin>>n;
 ll arr[1001];
 f(i,0,n)
 cin>>arr[i];
 max_so_far=-101;
 f(i,0,n)
 {
     sum=max(sum+arr[i],arr[i]);
     max_so_far=max(max_so_far,sum);
     //max_so_far=max(max_so_far,arr[i]);
     /*if(max_so_far+arr[i]>max_so_far)
     max_so_far=max_so_far+arr[i];
     if(max_so_far<arr[i])
     max_so_far=arr[i];*/
 }
 cout<<max_so_far<<endl;
    }

}


