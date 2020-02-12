// Method1 : Inorder traversal

//Method 2: using int_min and int_max
return checkBST(root, INT_MIN, INT_MAX);

bool checkBST(Node *root, int min, int max) {
    if(root == NULL)
        return true;

    if(node->data < min || node ->data > max)
        return false;

    return checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);
}

//Method 3: Using left and right pointers and avoiding min and max
bool checkBST(Node *root, Node *min = NULL, Node *max = NULL){
    if(root == NULL){
        return true;
    }

    if(min && root->data < min->data)
        return false;

    if(max && root->data > max->data)
        return false;

    return checkBST(root->left, min, root) && checkBST(root->right, root, max);
}