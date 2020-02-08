/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
bool func(struct Node *root,vector<struct Node *>&path,int key)
{
    if(root==NULL)
    return false;
    
    path.push_back(root);
    
    if(root->data==key)
        return true;
   
    if((root->left&&func(root->left,path,key))||(root->right&&func(root->right,path,key)))
      return true;
    
    path.pop_back();
    return false;
}
Node * LCA(Node* root ,int n1 ,int n2 )
{
    int i;
    bool ispresent1,ispresent2;

   vector<struct Node*>path1;
   vector<struct Node*>path2;

   ispresent1=func(root,path1,n1);
   
   struct Node *ptr;
  ispresent2=func(root,path2,n2);
   if(ispresent1==false||ispresent2==false)
     return NULL;
     
   for(i=0;i<path1.size()&& i<path2.size();i++)
   {
       if(path1[i]==path2[i])
           ptr=path1[i];

       else
       break;
       
   }
   return ptr;
}
