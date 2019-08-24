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

void levelOrder(struct node *root) {
  
  struct node *t;
  if(root==NULL)
  return;
  else
  {
      queue<struct node *>q;
      q.push(root);
      while(q.size()!=0)
      {
          t=q.front();
          q.pop();
          cout<<t->data<<" ";
          if(t->left!=NULL)
          q.push(t->left);
          if(t->right!=NULL)
          q.push(t->right);
          cout<<endl;
      }
  }
  
}

int main()
{
    struct node *root;
    root=create(9);
    root->left= create(2);
    root->right= create(3);
    root->left->left  = create(4);
    root->left->right = create(5); 
    levelOrder(root);
	
	    
}
