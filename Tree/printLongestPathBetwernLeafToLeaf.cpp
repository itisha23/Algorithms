// as we know that diameter of the tree is the longest path from leaf to leaf in a tree

// so once we know that whoch node contains the maximum node, we can print the farthest root from that node on both sides but only that node which has the distanc e equal to heigt of the node since we know what height should go?

int getDiameter(Node *root, Node *&maxDiaNode, int &lh, int &rh, int &diameter) {

    if(root == NULL){
        return 0;
    }

    int left = getDiameter(root->left, maxDiaNode, lh, rh);
    int right = getDiameter(root->right, maxDiaNode, lh, rh);

    int dia = left+height+1;

    if(dia > diameter){
        diameter = dia;
        maxDiaNode = root;
        lh = left;
        rh = right;
    }

    return max(left, right) +1;

}

void printLongestLeafToLeaf(Node *root) {

    Node*maxDianode = root;
    int lh =0, rh =0, diameter =0;
    int height = getDiameter(root, maxDianode, lh, rh, diameter);

    // print the farthest leaf from maxDianode at at height lh;
    // this found can be used to mark if a path is found, if it is found, then don't print the other one.  also foun=1 and found=2 are used to remind us that whether we want to print in normal order or the reverse order.
    int found = 1;
     
    vector<int>vec;
    printFunc(maxDianode->left, vector<int>vec, found, lh);
    vec.clear();
    found = 2; // for right tree
    printFunc(maxDianode->right, vec, found, rh);

}

void printFunc(Node *root, vector<int>&vec, int found, int d) {

    if(root == NULL)
        return 
    
    if(d ==1 && (found ==1 || found==2)) {
        printVec(vec, found);
        found =3;
        return;
    }

    printFunc(root->left, vec, found, d-1);
    printFunc(root->right, vec, found, d-1);

    vec.pop_back();
}

void printVec(vector<int>vec, int found) {

    if(found == 1){
        for(i=vec.size()-1; i>=0; i--){
            cout<<vec[i]<<" ";
        }
    }

    else{
        for(i=0; i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }
}