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

bool isSafe(string s,string str,ll i)
{
   if(s.find(str[i])!=string::npos)
   {
      
        return false; 
   }
  
  return true;
}

void func(ll k,string str,vector<string>&vec,string s)
{
    ll n=str.size(),i;
    for(i=0;i<n;i++)
    {
        if(isSafe(s,str,i))
        {
             s=s+str[i];
             //cout<<s<<endl;
            if(s.size()<n)
            func(0,str,vec,s);
            else if(s.size()==n)
            vec.push_back(s);
            s.erase(s.size()-1,1);
        }
       
    }
    
}
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
      ll i;
     string str,s="";
     cin>>str;
     vector<string>vec;
     func(0,str,vec,s);
     sort(vec.begin(),vec.end());
     for(i=0;i<vec.size();i++)
       cout<<vec[i]<<" ";
     cout<<endl;
  }   
}
