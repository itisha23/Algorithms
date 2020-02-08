struct Node {
    Node *left;
    Node *right;
    int data;
    Node *parent;
}

// Here the two nodes are given in the form of nodes and not int
//Method1 : using map to store parent of all nodes

Node* lca(Node* root, Node *node1, Node* node2) {

    if(root == NULL)
        return NULL;

    set<Node*>se;

    Node* node = node1;

    while(node) {
        se.insert(node);
        node = node->parent;
    }

    node = node2;
    while(node) {
        if(se.find(node) != se.end()) {
            return node;
        }
        node = node->parent;
    }
}

//T(n) : O(hlogh) // beacuse it will take log(h) time to insert in set and maximum height is h only.

//Method 2: Optimisation of method over space and time
// Strategy: if both nodes are at same level, then we just need to move up: so why not mpve until you reach the same height

int findDepth( Node*node) { // is easier since parent pointer is given

    
    int count=0;
    while(node){
        node = node->parent;
        count++;
    }
    return count;
}

Node *findLCAatSameHeight(Node *node1, Node* node2) {

    while(node1 != node2){
        node1 = node1->parent;
        node2 = node2->parent;
    }

    return node1;
}


Node *lca(Node *root, Node* node1, Node* node2) {

    int h1 = findDepth(node1);
    int h2 = findDepth(node2);

    if(h1 == h2){
        return findLCAatSameHeight(node1, node2);
    }

    
    if(h1 > h2){

        int diff = h1-h2;
        while(diff){
            node1 = node1->parent;
        }
        return findLCAatSameHeight(node1, node2);
    }

    else {
        int diff = h2-h1;
        while(diff){
            node2 = node2->parent;
        }
        return findLCAatSameHeight(node1, node2);
    
    }

    // may be you want to try out swapping nodes to prevent the repetition of code
    if(h1 < h2) {
        swap(node1, node2);
        swap(h1, h2);
    }
    int diff = h1-h2;
    while(diff){
        node1 = node1->parent;
    }
    return findLCAatSameHeight(node1, node2);

}

