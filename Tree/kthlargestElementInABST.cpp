// You can simly do reverse inorder tarversal. remember you have to reverse inorder traversal

// now the challenge is you have to this in constant space
// whenever you hear constant space think of morris inorder traversal

// now here you have to do reverse morris inorder traversal


void reverseMorris(Node *root) {
    if(root == NULL)
        return;

    Node *curr = root;

    while(curr) {

        if(curr ->right == NULl){
            cout<<curr->data<<endl;
            curr = curr->left;
        }

        Node *pre = curr->right;
        while(pre->left && pre->left != curr){
            pre = pre-left;
        }

        if(pre->left == NULL) {
            pre->left = curr;
            curr = curr->right;
        }
        else {
            pre->left = NULL;
            cout<<curr->data<<endl;
            curr = curr->left;
        }
    }
}