

// find lca of two nodes and then find distance form lca to one node and lca to other node and add then both
// once find lca you can simply use a function that calculates distance between a root and a node n1

int findDistance(Node *root, int n1, int n2) {

    if(root ==  NULL)
        return;

    Node *lca = findLca(root, n1, n1);

    if(lca->key!= n1 && lca->key!= n2) {
        return findDistanceBetweenRootAndNode(lca, n1, 0) + findDistanceBetweenRootAndNode(lca, n2, 0);
    } else if(lca->key == n1) {
         return findDistanceBetweenRootAndNode(lca, n2, 0);
    } 
    return findDistanceBetweenRootAndNode(lca, n1, 0);
    
}

//a  functionto get a distance between a root and n1 where we are sure that n1 is present in a tree rooted with root
int findDistanceBetweenRootAndNode(Node *root, int n, int level) {

    if(root == NULL)
        return -1;

    if(root ->key == n)
        return level;
    }

    int left = findDistanceBetweenRootAndNode(root->left, n, level+1);
    if(left != -1){
        return left;
    }
    return findDistanceBetweenRootAndNode(root->right, n, level+1);
}