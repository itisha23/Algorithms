#include<bits/stdc++.h>
using namespace std;
int main() {
    set<int>se;
    se.insert(5);
    se.insert(1);
    se.insert(7);
    se.insert(2);

    vector<int>vec;
    vec.push_back(2);vec.push_back(1);vec.push_back(25);vec.push_back(12);

    vector<int>::iterator it1;
    for(it1=vec.begin(); it1 < vec.begin()+2; it1++ ){
        cout<<*it1<<endl;
    }

    // set<int>::iterator it;

    //  for(it=se.begin(); it < se.begin()+2; it++ ){
    //     cout<<*it<<endl;
    // }
}