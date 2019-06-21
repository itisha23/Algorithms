/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// Recursive function to print right view of a binary tree.
void printKdistance(Node *root, int k)
{
  // Your code here
     struct Node *ptr;
      if(root==NULL)
         return;
     queue<pair<struct Node*,int>  >q;
     q.push(make_pair(root,0));
     while(q.empty()!=1)
     {
         ptr=q.front().first;
         int a=q.front().second;
         if(a==k)
         {
             cout<<ptr->data<<" ";
         }
         q.pop();
         if(ptr->left!=NULL)
          q.push(make_pair(ptr->left,a+1));
         if(ptr->right!=NULL)
           q.push(make_pair(ptr->right,a+1));
     }
  
 }
 
 KthDistanceFromTheRootOfTheTree.cpp
