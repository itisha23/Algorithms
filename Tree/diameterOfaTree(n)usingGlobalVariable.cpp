/* Diameter of a tree */
/*Structure of a tree */
/* struct Node{
      struct Node *left;
      struct Node *right;
      }
  int diahei(struct Node *node,int &height)
{
    int lh=0,rh=0;
   if(node==NULL)
     return 0;
    
  int ld=diahei(node->left,lh);
  int rd=diahei(node->right,rh);
  height=max(lh,rh)+1;
  return max(lh+rh+1,max(ld,rd));
}
int diameter(Node* node)
{
   // Your code here
   int h=0;
return diahei(node,h);
}
