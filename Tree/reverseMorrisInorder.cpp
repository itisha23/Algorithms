void func(Node *root) {

    if(root == NULL)
        return;

    Node *curr = root;

    while(curr) {

        if(curr->right == NULL) {
            cout<<curr ->data<<endl;
            curr = curr->left;
        }

        Node *pre = curr->right;
        while(pre->left != NULL && pre->left!- curr) {
            pre = pre ->left;
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

// Just look at Rt R Lt very carefully and code and see what should happen after each move. very easy if you take one example and code the above problem.