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