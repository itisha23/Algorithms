
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

int  printAllNodes(Node *root, int key, int k) {

    if(root == NULL)
        return 0;

    if(root->data == key) {
        return 0;
    }

    int dleft = printAllNodes(root->left, key, k);

    if(dleft!=-1) {

        if(dLeft+1== k){
            cout<<root->data<<endl;
        }

        else {
            printAllNodesATADistanceFromRoot(root->right, k-dleft-2);
        }

        return 1+dleft;
    }

    int dright =printALLNodes(root->right, key, k);

    if(dRight!=- 1) {

        if(dRight+1 == k){
            cout<<root->data<<endl;
        } else {
            printAllNodesATADistanceFromRoot(root->left, k-dRight-2);
        }

        return 1+dRight;
    }

    return -1;
}
