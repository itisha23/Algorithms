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
        int hash[26]={0};
        int n,i;
        
        pair<int,char>p,prev;
        n=s.size();
        f(i,0,n)
            hash[s[i]-'a']++;
        
        priority_queue<pair<int,char> >pq;
        f(i,0,26){
            if(hash[i]){
                char x= i+'a';
                pq.push(make_pair(hash[i],x));
            }
        }
        
        prev = make_pair(-1,'#');
        string ans ="";
        
        while(!pq.empty()){
            p = pq.top();
            pq.pop();
            
            ans = ans+p.second;
            if(prev.first!=-1 ){
                pq.push(make_pair(prev.first,prev.second));
            }
            if(p.first-1 !=0){
                prev.first = p.first-1;
                prev.second = prev.second;
            }
            else{
                prev = make_pair(-1,'#');
            }
        }
        
        if(ans.size()==n)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
