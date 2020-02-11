// My method:
// find lca and hence the path

//Method2:

void func(Node *root, int n1, int n2) {

    if(root == NULL)
        return;

    vector<int>vec1;
    vector<int>vec2;

    findPathFromRoot(root, n1, vec1);
    findPathFromRoot(root, n2, vec2);

    int x = findIntersectionPoint(vec1, vec2);

    if(x == v1.size() -1 || x == v2.size() -1){
        if(x == v1.size()-1)
            printPath(vec2, x);
        else
        {
            printPath(vec1, x);
        }
        
    }

    else {
        printReversePath(vec1, x);
        printPath(vec2, x+1);
    }
}