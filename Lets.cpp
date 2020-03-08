#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

bool myComp(pair<int, pair<int, int>>p1, pair<int, pair<int, int>>p2){
    return p1.second.second < p2.second.second;
}


int main() {

    vector<pair<int, pair<int, int>>>vec;

    vec.push_back(make_pair(1, make_pair(2, 7)));
    vec.push_back(make_pair(3, make_pair(4, 2)));

    sort(vec.begin(), vec.end(), myComp);

    cout<<vec[0].second.second<<endl;
    cout<<vec[1].second.second<<endl;
}

//