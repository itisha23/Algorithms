// find if you can find a sorted subsequence in array in linear time
// You can use auxillary space

int findIndex(int arr[], int n) {

    // int smaller [n];
    // int greater[n];

    vector<int>smaller(arr, arr+n);
    vector<int>greater(arr, arr+n);

    for(i=1; i<n ;i++) {
        smaller[i] = min(smaller[i], smaller[i-1]);
    }

    for(i=n-2; i>=0; i++){
        greater[i] = max(greater[i], greater[i+1]);
    }

    for(i=0; i<n ;i++){
        if(greater[i] != arr[i] && smaller[i] != arr[i])
            return i;
    }

    return -1;
}