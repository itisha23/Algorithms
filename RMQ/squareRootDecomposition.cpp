#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b; i++)

int main() {
    
    int n=10;

    int arr[]={3, 5, 1, 9, 10, 4, 8, 2 ,3, 7};

    int x= ceil(sqrt(n));

    int sqrt_array[x];
    memset(sqrt_array, 0, sizeof(sqrt_array));

    // y=0;
    // for(i=0; i<n ;i+= x) {
    //     j=i;
    //     count=0;
    //     sum=0;
    //     while(j< n && count<x) {
    //         sum + = arr[i];
    //         count++;
    //         j++;
    //     }
    //     sqrt_array[y++] = sum;
    // }

    // now we have the array which holds sum of sqrt(n) blocks
   
    // A better way of  preprocessing the array : copied from geeks
    y=0;
    f(i, 0, n) {
        if(i%x ==0) {
            y++;
        }
        sqrt_array[y]+= arr[i];
    }

}

int rangeQuerySum(int arr[], int sqrt_array[], int block_size, int l, int r) {

    int sum =0;

    while(l<=r && l%block_size !=0) {
        sum+=arr[l];
        l++;
    }

    while(l+block_size-1<=r) {
        sum+=  sqrt_array[l/block_size];
        l += block_size;
    }

    // last sum
    while(l<=r) {
        sum+= arr[i];
        l++;
    }

    return sum;
}

void updateSum(int arr[], int sqrt_array[], int block_size, int idx, int value) {

    int block_no = idx/ block_size;

    sqrt_array[block_no] + = value  - arr[idx];
    arr[idx] = value;
}