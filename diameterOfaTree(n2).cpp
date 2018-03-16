/* Diameter of a tree */
/*Structure of a tree */
/* struct Node{
      struct Node *left;
      struct Node *right;
      }
      
int height(struct Node *node)
{
   if(node==NULL)
    return 0;
   int lh=height(node->left);
   int rh=height(node->right);
   
   return max(lh,rh)+1;
}

int diameter(struct Node *node)
{
     if(node==NULL)
     return 0;
     int lh=height(node->left);
     int rh=height(node->right);
     
     int ld=diameter(node->left);
     int rd=diameter(node->right);
     
     return max(lh+rh+1,max(ld,rd));
     
}
