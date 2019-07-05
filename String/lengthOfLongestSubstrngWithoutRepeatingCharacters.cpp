using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
          ll n=s.size(),i,j,ans;
        ll hash[257];
        f(i,0,257)
        hash[i]=-1;
        
      
        ans=1;
       hash[s[0]]=0;
       
        i=0;j=1;
        f(j,1,n)
        {
            if(hash[s[j]]==-1)
            {
              hash[s[j]]=j;
              ans=max(ans,j-i+1);
            }
           else if(hash[s[j]]<i)
            {
              hash[s[j]]=j;
              ans=max(ans,j-i+1);
             
            }
          else
          {
              i=hash[s[j]]+1;
              hash[s[j]]=j;
          }
        }
        cout<<ans<<endl;
    }
}
