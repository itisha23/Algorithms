#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b; i++)

int main() {
    
}


//Analysis of segment tree
// array has n nodes 
// now if you divide this array into two halves, this will always o upto ceil(log2(n) ) + 1 , which is the height of tree . take perfect binary tree and assume extra nodes
// Now  a perfect binary tree of height h has 2^(h+1) - 1 nodes;
void preprocess(int arr[], int n) {

    int height = (int)ceil(log(n)) + 1;

    int tree_size = pow(2, height) - 1;

    int tree [tree_size];

    //construct

    int tree_index =0;
    int tot_sum = constructTree(arr, 0, n-1, tree, tree_index);
}

void constructTree(int arr[], int start, int end, int tree[], int tree_index) {

    if(start == end)
        tree[tree_index] = arr[start];

    int mid = (end - start)/2;

    tree[tree_index] = constructTree(arr, start, mid, tree, 2*tree_index+1) + constructTree(arr, mid+1, end, tree, 2*tree_index+2);

    return tree[tree_index];

}

int query(int tree[], int qstart, int qend, int start_sgtree, int end_sgtree, int tree_root_index) {

    // qStart and qend lies within range then simply return
    if (start_sgtree >= qstart && end_sgtree < =qend) {
        return tree[tree_root_index];
    }

    // outside range
    if(qstart > end_sgtree || qend < start_sgtree)
        return 0;

    int mid   = (start_sgtree + end_sgtree)/2;

    return query(tree, qstart,  qend, start_sgtree, mid, 2*tree_root_index+1) + query(tree, qstart, qend, mid+1, end_sgtree, 2*tree_root_index+2);
}

//T(n) : O(logn)
oid updateValueUtil(int *st, int ss, int se, int i, int diff, int si)  
{  
    // Base Case: If the input index lies outside the range of  
    // this segment  
    if (i < ss || i > se)  
        return;  
  
    // If the input index is in range of this node, then update  
    // the value of the node and its children  
    st[si] = st[si] + diff;  
    if (se != ss)  
    {  
        int mid = getMid(ss, se);  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}  
  
// The function to update a value in input array and segment tree.  
// It uses updateValueUtil() to update the value in segment tree  
void updateValue(int arr[], int *st, int n, int i, int new_val)  
{  
    // Check for erroneous input index  
    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
  
    // Get the difference between new value and old value  
    int diff = new_val - arr[i];  
  
    // Update the value in array  
    arr[i] = new_val;  
  
    // Update the values of nodes in segment tree  
    updateValueUtil(st, 0, n-1, i, diff, 0);  
}  