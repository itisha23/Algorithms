#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b;i++)
int main() {
    string s;
    cin>>s;

    int hash[26]={0};

    f(i,0,s.size()){
        hash[s[i]-'a']++;
    }

    int ans =0;
    map<int,int, greater<int>>mp;

    f(i,0,26){
        if(hash[i]){
            mp[hash[i]]++;
        }
    }

    for(auto it=mp.begin(); it!=mp.end(); it++) {
        
        while(it->second > 1) {
            ans++;

            it->second--;
            mp[it->first-1]++;
        }
    }

    cout<<ans<<endl;
}