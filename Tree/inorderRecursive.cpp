#include<bits/stdc++.h>
using namespace std;
struct node
{
    struct node*left;
    int data;
    struct node *right;
};
struct node *create(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorderrecursive(struct node*root)
{
    if(root==NULL)
    return;
    inorderrecursive(root->left);
    cout<<root->data<<" ";
    inorderrecursive(root->right);
    
}

int main()
 {
	struct node *root;
	
	    root=create(9);
	    root->left        = create(2);
        root->right       = create(3);
        root->left->left  = create(4);
        root->left->right = create(5); 
        inorderrecursive(root);
        cout<<endl;
        inorderrecursive(root);
  }
