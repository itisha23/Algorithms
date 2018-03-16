/* Diameter of a tree */
/*Structure of a tree */
/* struct Node{
      struct Node *left;
      struct Node *right;
      }
      
pair<int,int> calc(struct Node *node)
{
    if(node==NULL)
    {
        return make_pair(0,0);
    }
    pair<int,int>p1=calc(node->left);
    pair<int,int>p2=calc(node->right);
    
    int dia=max(p1.first+p2.first+1,max(p1.second,p2.second));
    int hei=max(p1.first,p2.first)+1;
    
    return make_pair(hei,dia);
    
}

int diameter(Node* node)
{
  pair<int,int>p;
  p=calc(node);
  return p.second;
}

