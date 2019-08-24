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
        ll n,i,pf=0,f;
        cin>>n;
        ll arr[n];
        f(i,0,n)
        cin>>arr[i];
        cin>>f;
        vector<int>vec;
        f(i,0,n)
        {
            if(vec.size()<f)
            {
                if(find(vec.begin(),vec.end(),arr[i])==vec.end())
               {
                   vec.push_back(arr[i]);
                   pf++;
               }
               else
               {
                   vec.erase(find(vec.begin(),vec.end(),arr[i]));
                   vec.push_back(arr[i]);
                   
               }
            }
            else
            {
                if(find(vec.begin(),vec.end(),arr[i])==vec.end())
                {
                    vec.erase(vec.begin());
                    pf++;
                    vec.push_back(arr[i]);
                }
                else
                {
                    vec.erase(find(vec.begin(),vec.end(),arr[i]));
                    vec.push_back(arr[i]);
                }
            }
        }
        cout<<pf<<endl;
    }
}
