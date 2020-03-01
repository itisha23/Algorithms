#include<bits/stdc++.h>
using namespace std;
int main() {
    map<int, int>mp;
    mp[4] = 5;
    mp[7] = 10;
    mp[10] = 0;

    for(auto it = mp.begin(); it!=mp.end();it++){
        cout<<it->first<<endl;

        if(it->first == 7)
            mp[5] = 11;
    }
}