
// We can simply prine the tree in botto  up amnner
// ANd we always a leaf node so it will be easier

Node *prune(Node *root, int k) {
    if(root == NULL)
        return NULL;

    root->left = prune(root->left, k);
    root->right = prune(root->right, k);

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    return root;

}