*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

bool func(Node *root, int mini, int maxi){
    
    if(root==NULL)
        return true;
    
    if(root->data<mini || root->data>maxi)
        return false;
        
    return func(root->left, mini, root->data) && func(root->right, root->data,maxi);
}
bool isBST(Node* root) {
    
    return func(root, INT_MIN, INT_MAX);
}
