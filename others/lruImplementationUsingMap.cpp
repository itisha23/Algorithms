#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,pf=0,f,mini,key;
        cin>>n;
        ll arr[n];
        f(i,0,n)
        cin>>arr[i];
        cin>>f;
        map<int,int>mp;
        f(i,0,n)
        {
            if(mp.size()<f)
            {
                if(mp.count(arr[i])==0)
                {
                    mp[arr[i]]=i;
                    pf++;
                }
                else
                mp[arr[i]]=i;
            }
            else
            {
                if(mp.count(arr[i])==0)
                {
                    mini=INT_MAX;
                    for(auto it=mp.begin();it!=mp.end();it++)
                    {
                        if(it->second<mini)
                        {
                            key=it->first;
                            mini=it->second;
                        }
                    }
                    mp.erase(key);
                    pf++;
                    mp[arr[i]]=i;
                }
                else
                {
                    mp[arr[i]]=i;
                }
            }
        }
        cout<<pf<<endl;
    }
}
