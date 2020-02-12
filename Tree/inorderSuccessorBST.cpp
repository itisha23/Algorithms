//Method 1:

Node *inorder(Node *root, Node *node) {

    if(root == NULL)
        retunrn NULL;

    if(node->right != NULL){

        succ = root->right;
        while(succ->left)
            succ = succ->left;
    } else {

        curr = root;
        while(curr) {
            if(curr->data > node->data){
                succ = curr;
                curr = curr->left;
            }

            else if(curr ->data < node->data){
                curr = curr->right;
            }
            else
            {
                break;
            }
            
        }
    }
}

//Method 2: Using parent pointer
// If right subtree is null then keep finding that parent until which that node is ot the left child of its parent
// IN this case no root pointer is required

Node *inorder(Node *node) {

    if(node == NULL)
        retunrn NULL;

    if(node->right != NULL){

        succ = node->right;
        while(succ->left)
            succ = succ->left;
    } else {

      curr = node;
      parent = curr->parent;
      while(parent && parent->right == parent){
          curr = parent;
          parent = parent->parent;
      }

      return parent;

    }
}