#include<bits/stdc++.h>
using namespace std;


void func(int x, int y, int &ans){
    if(y==0){
        return ;
    }

    ans= ans+x;
    y--;
    func(x, y, ans);
}

int main(){

    int x, y;
    cin>>x>>y;
    int ans =0;
    func(x, y, ans);
    cout<<ans<<endl;
}