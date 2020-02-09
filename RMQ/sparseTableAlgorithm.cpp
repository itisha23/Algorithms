#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b; i++)

int main() {
    
}

void preprocess(int arr[], int n) {

    int x = log(n);

    int dp[n] [x+1];

    for(i=0; i<n; i++)
        dp[i][0] = i; // the subset contains only one element

    for(j=1; (1<<j )<=n; j++) { // better way of 
        for(i=0; i+ (1<<j) -1<n; i++) {

            dp [i][j] = min(dp[i][j-1], dp[i][i+ (1<<j)-1]);
        }
    }
}

//T(n) : O(logn * n);

// query time


// we calculate from left till highets power of 2 which can be calculated

int query(int low, int high) {

    int n= high-low+1;
    int k = log(n);

    return min(dp[low][k], dp[low+l-(1<<k)][k]);
}