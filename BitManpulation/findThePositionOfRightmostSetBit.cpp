#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        
        int position=1;
        int x = 1,y;
        
        if(n==0){
            cout<<"0"<<endl;
        } else {
            while(1){
            
            y = n & x;
            if(y){
                break;
            }
            position++;
            x = x<<1;
        }
        
        cout<<position<<endl;
        }
        
    }
}

//METHOD 2: 
/**
 * Take the two's complement of the number.
 * SO you see all bits which were 0 before first rightmost set bit remain 0 after two's complement and only the first set bit remain 1. (which got 0 in 1'com
 * plement but become 1 again after it)
 * Take the & of n & -n
 * Take log2, you will get the position
 * Add 1
 * 
 * */

int x = log2(n & -n);
cout<<x+1<<endl;