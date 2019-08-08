#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x,k;
        cin>>k>>n;
        priority_queue<int,vector<int>,greater<int> >pq;
        while(n--){
            cin>>x;
            if(pq.size()<k){
                pq.push(x);
            }
            else{
                if(x>pq.top()){
                    pq.pop();
                    pq.push(x);
                }
            }
            if(pq.size()<k)
                cout<<-1<<" ";
            else
                cout<<pq.top()<<" ";
        }
        cout<<endl;
    }
}
