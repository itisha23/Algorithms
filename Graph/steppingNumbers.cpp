#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

void func(ll m, ll n ,ll num,ll &count){
    
    queue<ll>q;
    q.push(num);
    
    ll x,x1,x2,rem;
    while(!q.empty()){
        
        x=q.front();
        q.pop();
        
        if(x>=m && x<=n)
           count++;
        
        if(x==0 || x>n)
            continue;
        rem = x%10;
        x1 = x*10+rem+1;
        x2 = x*10+rem-1;
        
        if(rem!=0)
        q.push(x2);
        if(rem!=9)
        q.push(x1);
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll m,n,i,count=0;
        cin>>m>>n;
        
        for(i=0;i<=9;i++)
            func(m,n,i,count);
        cout<<count<<endl;
    }
}
