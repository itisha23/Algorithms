/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */


int maxLevelSum(Node * root)
{
   //Your code here
   int maxi,sum;
   if(root==NULL)
   return 0;
   queue<struct Node *>q1,q2;
   q1.push(root);
   struct Node *node;
   maxi=INT_MIN;
   while(q1.empty()!=1 || q2.empty()!=1)
   {
       sum=0;
       while(q1.empty()!=1)
       {
           node=q1.front();
           sum+=node->data;
           q1.pop();
           if(node->left!=NULL)
           q2.push(node->left);
           if(node->right!=NULL)
           q2.push(node->right);
       }
       if(sum>maxi)
       maxi=sum;
       sum=0;
        while(q2.empty()!=1)
       {
           node=q2.front();
           sum+=node->data;
           q2.pop();
           if(node->left!=NULL)
           q1.push(node->left);
           if(node->right!=NULL)
           q1.push(node->right);
       }
       if(sum>maxi)
       maxi=sum;
       
   }
   return maxi;
   
}
