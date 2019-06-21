*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*Your code here*/
void inorder(Node* root,vector<int>&vec)
{
    if(root==NULL)
    return;
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}
void func(struct Node*root,vector<int>&vec,int &i)
{
    if(root==NULL)
    return ;
    func(root->left,vec,i);
    root->data=vec[i++];
    func(root->right,vec,i);
}
 
Node *binaryTreeToBST (Node *root)
{
//Your code here
  vector<int>vec;
  inorder(root,vec);
  sort(vec.begin(),vec.end());int i=0;
  func(root,vec,i);
  return root;
}
