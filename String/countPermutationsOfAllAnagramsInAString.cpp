#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b; i++)

#define MAX_CHARS 256

int main() {
    
    ll t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        
        ll m, n, ans=0, i, j, count;
        
        m = s1.size(); n=s2.size();
        int hash1[MAX_CHARS] = {0};
        int hash2[MAX_CHARS] = {0};
    
        
        if(s1.size() < s2.size()) {
            cout<<ans<<endl;
        } else {
            
            for(i=0; i<n; i++)
                hash2[s2[i]]++;
            
            i=0; j=0; count=0;
            while(i<n) {
                
                hash1[s1[i]]++;
                
                if(hash1[s1[i]] <= hash2[s1[i]])
                    count++;
                    
                i++;
            }
            
            for(i=n; i<m ; i++) {
                
                if(count == n){
                    ans++;
                }
                
                hash1[s1[i-n]]--;
                
                if(hash2[s1[i-n]] && hash1[s1[i-n]] < hash2[s1[i-n]])
                    count--;
                    
                hash1[s1[i]]++;
                
                if(hash1[s1[i]] <= hash2[s1[i]])
                    count++;
                
            }
            
            if(count == n){
                    ans++;
                }
                
            cout<<ans<<endl;
        }
    }
}