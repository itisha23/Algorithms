*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*  modifies the root of the bst */
void inorder(Node *root,int &sum)
{
    if(root==NULL)
    return;
    inorder(root->left,sum);
    sum=sum+root->data;
    inorder(root->right,sum);
}

void func1(Node *root,int &sum)
{
if(root==NULL)
return;
    int temp;
    func1(root->left,sum);
    temp=root->data;
    
    root->data=sum;
    sum=sum-temp;
    func1(root->right,sum);
}

void modify(Node **root)
{
  if(*root==NULL)
    return;
  int sum=0;
  inorder(*root,sum);
  func1(*root,sum);
  //ino(*root);
}
