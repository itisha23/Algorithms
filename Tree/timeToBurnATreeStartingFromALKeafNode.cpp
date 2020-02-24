// first: time
// height
// flag

tuple<int, int, bool> func(Node *root, Node *node) {
    if(root == NULL) {
        return make_tuple(0,0, false);
    }

    if(root == node ){
        //flag=1;
        int h = calcualateHeight(node);
        return make_tuple(0+h-1, h, 1);
    }

    tuple(int, int, bool) left  = func(root->left, node);
    tuple(int, int, bool) right = func(root->right, node);

    if(get<2>left == false && get<2>right == false) {
        //return make_tuple(max(left.first, right.first)+1, max(left.second, right.second)+1, false);
        return make_tuple(max(get<0>(first), get<0>(right))+1, max(get<1>(left), get<1>(right))+1, false);
    }

    if(left.third) {
        //return make_tuple(left.first+right.second+1, max(left.second, right.second)+1, true);
        return make_tuple(get<0>(left)+get<1>(second)+1, max(get<1>(left), get<1>(second))+1, true);
    }

    if(right.third) {
        //return make_tuple(right.first+left.second+1, max(left.second, right.second)+1, true);
        return make_tuple(get<0>(right)+get<1>(left)+1, max(get<1>(left), get<1>(right))+1, true);
    }
}