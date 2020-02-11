
void printAllNodesATADistanceFromRoot(Node* root, int k) {

    if(root == NULL) {
        return ;
    }

    if(k==0){
        cout<<node->data<<endl;
        return;
    }

    printAllNodesATADistanceFromRoot(root->left, k-1);
    printAllNodesATADistanceFromRoot(root->right, k-1);
}