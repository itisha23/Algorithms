#include<iostream>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b ;i++) 

long long int merge(long long int arr[], long long int low, long long int mid, long long int high, long long int n) {

   
    long long int temp[n];
    long long int i, j, k, count = 0;

    i = low;
    j = mid + 1;
    k = low;

    count = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++)
        arr[i] = temp[i];

    return count;
}


long long int countInversions(long long int arr[], long long int low, long long int high, long long int size) {

    if (low >= high)
        return 0;

    long long int mid = (high + low) / 2;

    long long int left_count = countInversions(arr, low, mid, size);
    long long int high_count = countInversions(arr, mid + 1, high, size);

    long long int mergecount = merge(arr, low, mid, high, size);

    return left_count + high_count + mergecount;

}

int main() {

    long long int t;
    cin>>t;
   
    while (t--) {
        long long int n, i;
        cin >> n;
        long long int arr[n];
        //n = 5;
        //long long int arr[5] = {2, 4, 1, 3, 5};
        f(i, 0, n)
            cin >> arr[i];

        long long int count = countInversions(arr, 0, n - 1, n);

        std::cout << count << endl;
    }
}



