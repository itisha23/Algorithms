// Method 1: 
// print the last node of each level using level order traversal

// Method2: may be preorder traversal
// same as left view of bianry tree
// But the idea is to traverse right node first and then the left node

printRightView(Node *root, 1, 0)

void printRightView(Node *root, int level, int &maxlevel) {

    if(root == NULL)
        return ;
    
    if(maxlevel < level) {
        maxlevel = level;
        cout<<root->data;
    }

    printRightView(root->right, level+1, maxLevel);
    printRightView(root->left, level+1, maxLevel);
}