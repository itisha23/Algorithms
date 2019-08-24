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
int height1(struct Node *node)
{
    if(node==NULL)
    return 0;
    int lh=height1(node->left);
    int rh=height1(node->right);
    return max(lh,rh)+1;
}
void sumgivenlevel(struct Node *node,int level,int &sum)
{
    if(node==NULL)
    return ;
    if(level==1)
    {
        sum=sum+node->data;
    }
    sumgivenlevel(node->left,level-1,sum);
    sumgivenlevel(node->right,level-1,sum);
}

int maxLevelSum(Node * root)
{
   //Your code here
   int i,sum,maxi=INT_MIN;
   int levels=height1(root);
   for(i=1;i<=levels;i++)
  {
      sum=0;
      sumgivenlevel(root,i,sum);
      if(sum>maxi)
      maxi=sum;
  }
  return maxi;
}
