#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b ;i++) 

int main() {

    long long int t;
    cin>>t;
   
    while (t--) {
        long long int n, i;
        cin >> n;
        long long int arr[n];

        f(i, 0, n)
            cin >> arr[i];

        multiset<long long int> set1; 
   
    long long int invcount = 0;
    multiset<long long int>::iterator itset1; 
    for ( i=0; i<n; i++) 
    { 
       
        itset1 = set1.upper_bound(arr[i]); 
        invcount += distance(itset1, set1.end()); 
        set1.insert(arr[i]);
    } 
    cout<<invcount<<endl; 
    }
}



