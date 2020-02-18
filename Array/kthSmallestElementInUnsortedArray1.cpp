using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
#include<bits/stdc++.h>

// here the expected time compexity is O(n) but worst case is still O(n2) if randomised doesn't work properly.

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

int partition(int arr[], int l, int r) 
{ 
	int x = arr[r], i = l; 
	for (int j = l; j <= r - 1; j++) 
	{ 
		if (arr[j] <= x) 
		{ 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 


int randomPartition(int arr[], int l, int r) 
{ 
	int n = r-l+1; 
	int pivot = rand() % n; 
	swap(&arr[l + pivot], &arr[r]); 
	return partition(arr, l, r); 
} 



int kthSmallest(int arr[], int l, int r, int k) 
{
	if (l<=r) 
	{ 
		// Partition the array around a random element and 
		// get position of pivot element in sorted array 
		int pos = randomPartition(arr, l, r); 

		// If position is same as k 
		if (pos==k ) 
			return arr[pos]; 
		if (pos > k) // If position is more, recur for left subarray 
			return kthSmallest(arr, l, pos-1, k); 

		// Else recur for right subarray 
		return kthSmallest(arr, pos+1, r, k); 
	} 

	// If k is more than the number of elements in the array 
	return INT_MAX; 
} 





int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,k,a;
        cin>>n;
        int arr[n];
        f(i,0,n)
        cin>>arr[i];
        cin>>k;
        cout<<kthSmallest(arr, 0, n-1, k-1)<<endl;
    }
}



