//Method 1:
    //Use q and simply print the first node

//Method 2:
    //Preorder traversal


// Since we are doing in the preorder fashion, we should always get the first node when our level crosses the max level

printBottomView(root, 1, maxlevel);

void printBottomView(Node *root, int level, int &maxlevel) {

    if(root == NULL)
        return;
    
    if (maxlevel < level) {
        cout<<root->data;
        maxlevel = level;
    }i

    printBottomView(root->left, level+1, maxlevel);
    printBottomView(root->right, level+1, maxlevel);
}