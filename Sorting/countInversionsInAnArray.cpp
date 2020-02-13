#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b ;i++) 

int merge(int arr[], int low, int mid, int high, int n) {
    
    if(low>=mid)
        return 0;
        
    int temp[n];
    int i, j, k, count=0;
    
    i=low;
    j=mid+1;
    k = low;
    
    count =0;
    
    while(i<= mid && j<=right) {
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            count+ = mid-i+1;
        }
    }
    
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    
   while(j<=high) {
       temp[k++] = arr[j++];
   } 

   for(i=low; i<=high; i++)
        arr[i] = temp[i];

    return count;
}


int countInversions(int arr[], int low, int high, int size) {
    
    if(low >=high)
        return 0;
    
    int mid = (high - low)/ 2;
    
    int left_count = countInversions(arr, low, mid, size);
    int high_count = countInversions(arr, mid+1, high, size);
    
    int mergecount = merge(arr, low, mid, high, size);
    
    return left_count + high_count + mergecount;
    
}

int main() {
    
    int t;
    cin>>t;
    while(t--) {
        int n, i;
        cin>>n;
        int arr[n];
        f(i,0,n)
            cin>>arr[i];
        
        int count = countInversions(arr, 0,  n-1, n);

        cout<<count<<endl;
    }
}



