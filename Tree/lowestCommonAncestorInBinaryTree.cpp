/*The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. If we assume that the keys n1
and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming 
that both keys are present). If root doesn’t match with any of the keys, we recur for left and right subtree. The node which has one key 
present in its left subtree and the other key present 
in right subtree is the LCA. If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.*/


struct Node *findLCA(struct Node* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report 
    // the presence by returning root (Note that if a key is 
    // ancestor of other, then the ancestor key becomes LCA 
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 


//But this method assumes that both keys are present in tree. How we change the solution so that it can return NUll  even if  one key is absent in tree using two variables
// Method2

struct Node* findLCAUtil(node * root, int n1, int n2, bool a, bool b) {

    if(root == NULL){
        return NULL;
    }

    if(root ->data  == n1) {
        a = true;
        return root;
    }

    if(root ->data == n2){
        b= true;
        return root;
    }

    node * left = func(root->left, n1, n2, a, b);
    node *right = func(root->right, n1, n2, a, b);

    if(left && right){
        return root;
    }

    return left != NULL? left : right;
}

bool findInSubtree(node *root, int key) {

    if(root == NULL)
        return false;

    if(root ->data == key)
        return true;

    return findInSubTree(root->left, key) || findInSubtree(root->right, key);

}

node *findLCA(node *root, int n1, int n2) {

    int a = false; int b = false;

    node *lca = findLCAUtil(root, a, b);

    if(a &&  b || a &findInSubtree(lca, n2) || b && findInSubtree(lca, n1))
        return lca;

    return NULL;
}

//T(n) : O(n)