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
   ll t,i,n;
   t=1;
   cin>>t;
   while(t--)
   {
     ll x1,y1,x2,y2,a1,b1,a2,b2;
     cin>>x1>>y1>>x2>>y2;
     cin>>a1>>b1>>a2>>b2;
     if(x2<a1 || y1<b2||x1>a2||y2>b1)
       cout<<"0"<<endl;
     else
       cout<<"1"<<endl;
       
   }
  
    
}


