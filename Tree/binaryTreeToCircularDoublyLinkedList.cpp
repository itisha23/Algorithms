void func(Node *node,Node *&prev,Node *&root)
{
    if(node==NULL)
    return;
    func(node->left,prev,root);
    if(prev==NULL)
    root=node;
    else
    prev->right=node;
    node->left=prev;
    prev=node;
    func(node->right,prev,root);
}
Node *bTreeToCList(Node *root)
{
    if(root==NULL)
    return root;
    Node *prev=NULL,*temp=root;
    func(temp,prev,root);
    prev->right=root;
    root->left=prev;
    return root;
}
