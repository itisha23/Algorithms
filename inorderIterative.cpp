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
void inorderiterative(struct node *root)
{
    if(root==NULL)
    return;
    stack<struct node*>s;
    struct node* current,*t;
    current=root;
    cout<<current->data<<endl;
    s.push(current);
     int a=s.size();
    cout<<a;
   
    while(s.size()!=  0)
    {
    cout<<"hi";
        while(current!=NULL)
        {
            current=current->left;
            s.push(current);
        }
        t=s.top();s.pop();
        cout<<t->data<<" ";
        current=t->right;
        if(current!=NULL)
        s.push(current);
    }
    
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
        inorderiterative(root);
  }
