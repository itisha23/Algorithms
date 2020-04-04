#include<bits/stdc++.h>
using namespace std;


struct comp{
    bool operator()(pair<int, int>p1, pair<int, int>p2) {
        return p1.second > p2.second;
    }
};

int main() {

    map<int, int, comp>mp;

    mp[1] = 5;
    mp[2] = 2;
    mp[3] =0;

    for (auto it = mp.begin(); it!=mp.end(); it++) {
        cout<<it->first<<" "<<it-second<<endl;
    }
} 