
Node *func(Node *root) {

    if(root == NULL || root->left == NULL  || root->right == NULL){
        return ;
    }

    func(root->left);
    func(root->right) ;

    int left =0; int right =0;

    if(root->left){
        left = root->left->data;
    }

    if(right) {
        right = root->right->data;
    }

    int diff = root->data - left -right;

    // if(root->left && root->right ) {
    //     if(root->data == root->left->data + root->right->data) {
    //         return;
    //     } else if (root->data < root->left->data + root->right->data) {
    //         root ->data = root->left->data + root->right->data;
    //     } else {
    //         diff = root->data - (root->left->data + root->right->data);

    //         increment(root->left, diff);
    //     }
    // }

    // else if(root->left) {
    //     if(root->data == root->left->data) {
    //         return;
    //     } else if(root->data < root->left->data) {
    //         root->data = root->left->data;
    //     } else {
    //         diff = root->data - root->left->data;
    //         increment(root->left, diff);
    //     }
    // } 

    // else if(root->right) {
    //     if(root->data == root->right->data) {
    //         return;
    //     } else if(root->data < root->right->data) {
    //         root->data = root->left->data;
    //     } else {
    //         diff = root->data - root->right->data;
    //         increment(root->left, diff);
    //     }
    // }

    //easier way

    if(diff > 0) {
        root ->data + = diff;
    }

    if(diff < 0) {
        if(root->left) {
            increment(root->left, -diff);
        } else {
            increment(root->right, -diff);
        }

    }

}

void increment(Node *root, int diff) {

    root->data + = diff;
    if(root->left) {
        increment(root->left, diff);
    } else if(root ->right)
    {
        increment(root->right, diff);
    }
    

}