
int maxPathInASingleTraversal(Node *root, int &ans) {
    if(root == NULL)
        return 0;

    int left = maxPathInASingleTraversal(root->left, ans);
    int right = ma(root->right, ans);

    int max_single = max(max(left, right)+root->data, root->data);

    int including_left_right = left+right+root->data;

    ans = max(ans, max(max_single, including_left_right));

    return max_single;
}