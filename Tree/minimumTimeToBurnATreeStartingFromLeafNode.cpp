

struct  metaData
{
    int lh; int rh; bool isPresent; int time;
};


void func2(Node *root, Node *target, metaData meta, int &ans) {

    if(root == NULL) {
        return;
    }

    if(root == target) {
        meta.isPresent = true;
        meta.time = 0;
        return;
    }

    metaData leftmeta
    func2(root->left, target, leftmeta, );

    metaData rightMeta;
    func2(root->right, target, rightMeta, ans);

    meta.contains = root->left && leftmeta.contains || root->right && rightMeta.contains;

    meta.time = root->left && leftmeta.contains ? leftmeta.time +1 : -1;
    if(meta.time != -1){
        meta.time = root->right && rightmeta.contains ? rightmeta.time + 1 : -1;
    }

    meta.lh = node->left ? max(leftmeta.lh, leftmeta.rh)+1 : 0;
    meta.rh = node->right ? max(rightmeta.lh, rightmeta.rh) + 1: 0;

    if(meta.contains) {
        if(root->left && leftmeta.contains)
            ans = max(ans, meta.time + meta.rh);
        
        if(root->right && rightmeta.contains)
            ans = max(ans, meta.time + meta.lh);
    }

}
void func(Node *root, Node *target) {

    if(root == NULL){
        return 0;
    }

    int ans =0;
    metaData meta;

    func2(root, target, meta, ans);

}