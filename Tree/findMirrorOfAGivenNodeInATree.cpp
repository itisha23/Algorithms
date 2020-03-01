Node *findMirrorNode(Node *root, int target){
    if(root == NULL)
        return NULL;
    if(root ->data  == target)
        return root;
    Node *ans = NULL;
    findMirrorUtil(root->left, root->right, target, ans);
    return ans;
}

void findMirrorUtil(Node* left, Node*right, int target, Node *ans) {
    if(left == NULL || right == NULL)
        return;
    
    if(left->data == target) {
         ans = right;
         return;
    }
       
    if(right->data == target) {
        ans = left;
        return;
    }
        

    findMirrorUtil(left->left, right->right, target, ans);
    if(ans == NULL){
        findMirrorUtil(left->right, right->lrft, target, ans);
    }
}