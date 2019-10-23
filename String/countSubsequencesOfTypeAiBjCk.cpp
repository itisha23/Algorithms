#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size(),i,acount=0,bcount=0,ccount=0;
        f(i,0,n){
            if(s[i]=='a')
                acount = 1+ 2*acount;
            else if(s[i] == 'b')
                bcount = acount + 2*bcount;
            else if (s[i]=='c')
                ccount = bcount + 2*ccount;
        }
        cout<<ccount<<endl;
    }
}
