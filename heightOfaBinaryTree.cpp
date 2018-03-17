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

int height(struct node *root)
{
   if(root==NULL)
    return 0;
  int lheight=height(root->left);
  int rheight=height(root->right);
  return max(lheight+1,rheight+1);
}

int main()
{
    struct node *root;
    root=create(9);
    root->left= create(2);
    root->right= create(3);
    root->left->left  = create(4);
    root->left->right = create(5); 
    cout<<height(root);
	    
}
