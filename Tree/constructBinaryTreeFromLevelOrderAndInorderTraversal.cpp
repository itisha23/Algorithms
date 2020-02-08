#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}

int search(int inorder[], int iStart, int iEnd, int key) {
    
    for(int i=iStart; i<=iEnd; i++){
        if(inorder[i] == key)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{       
    if(iStart > iEnd){
        return NULL;
    }
    
    Node *root = (Node*)malloc(sizeof(Node));
    root->key = levelOrder[0];
    root->left = NULL;
    root->right = NULL;
    
  
    
    int ind = search(inorder, iStart, iEnd, root->key);
    
    int lLevel [ind-iStart];
    int rLevel [iEnd - ind];
    
    int k=0,m=0;
    for(int i=1; i<n; i++){
        if(search(inorder, iStart, ind-1, levelOrder[i])!=-1){
            
            lLevel[k++] = levelOrder[i];
        }
        else if(search(inorder, ind+1, iEnd, levelOrder[i])!=-1){
            rLevel[m++] = levelOrder[i];
        }
    }
    
    root->left = buildTree(inorder, lLevel, iStart, ind-1,ind-iStart );
    root->right = buildTree(inorder, rLevel, ind+1, iEnd, iEnd-ind);
    
    return root;
}

//T(n) : O(n)3
//Optimisaion is this: O(n)2 solution

// can modify the search for creating left and right subarrays. 
int search(int inorder[], int iStart, int iEnd, int key) {
    
    for(int i=iStart; i<=iEnd; i++){
        if(inorder[i] == key)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{       
    if(iStart > iEnd){
        return NULL;
    }
    
    Node *root = (Node*)malloc(sizeof(Node));
    root->key = levelOrder[0];
    root->left = NULL;
    root->right = NULL;
    
  
    
    int ind = search(inorder, iStart, iEnd, root->key);
    
    unordered_set<int>se;
    
    for(int i= iStart; i<ind; i++){
        se.insert(inorder[i]);
    }
    
    
    int lLevel [ind-iStart];
    int rLevel [iEnd - ind];
    
    int k=0,m=0;
    for(int i=1; i<n; i++){
        if(se.find(levelOrder[i]) != se.end()){
            lLevel[k] = levelOrder[i];
            //cout<<lLevel[k]<<endl;
            k++;
        }
        else {
            rLevel[m] = levelOrder[i];
            //cout<<rLevel[m]<<endl;
            m++;
        }
    }
    
    root->left = buildTree(inorder, lLevel, iStart, ind-1,ind-iStart );
    root->right = buildTree(inorder, rLevel, ind+1, iEnd, iEnd-ind);
    
    return root;
}

// Optimisdtion 3: can aloso modify the search ininOrder traversal by storing them in an array












