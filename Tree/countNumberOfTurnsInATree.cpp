bool func(Node *root, int key, int count, int &ans, bool flag) {
    
    if(root== NULL){
        return false;
    }
    
    if(root->key == key){
        ans = count;
        return true;
    }
    
    bool left=false, right=false, temp; 
    
    if(root->left) {
       if(flag==1){
          
           temp = 0;
           left = func(root->left, key, count+1, ans, temp);
       } 
       else
       left = func(root->left, key, count, ans, flag);
    }
    
    if(root->right) {
        if(flag==0){
             temp = 1;
             right= func(root->right, key, count+1, ans, temp);
           
        } else
        right= func(root->right, key, count, ans, flag);
    }
    
    return left || right;
}

Node *findLca(Node *root, int first, int second) {
    if(root == NULL){
        return NULL;
    }
    
    if(root->key == first) {
        return root;
    }
    
    if(root->key == second) {
        return root;
    }
    
    Node *left = findLca(root->left, first, second);
    Node *right = findLca(root->right, first, second);
    
    if(left && right){
        return root;
    }
    
    if(left){
        return left;
    }
    
    else
    return right;
}
int NumberOFTurn(struct Node* root, int first, int second)
{
    bool left, right, flag;
    int count =0, ans =0, key1 =0, key2=0 ;
      
    Node* lca = findLca(root, first, second);
    
  
    
    if(lca == NULL)
    {
        return -1;
    }
    
    if(lca->key  == first){
        count=0; ans=0; flag=0;
        left = func(lca->left, second, count, ans, flag);
        if(left){
            if(ans)
                return ans;
            return -1;
        }
        count=0; ans=0; flag=1;
        right = func(lca->right, second, count, ans, flag);
        if(ans)
            return ans;
        return -1;
    }
    
    else if(lca->key == second) {
        count=0; ans=0; flag=0;
        left = func(lca->left, first, count, ans, flag);
        if(left){
            if(ans)
                return ans;
            return -1;
        }
        count=0; ans=0; flag=1;
        right = func(lca->right, first, count, ans, flag);
        if(ans)
            return ans;
        return -1; 
    }
    
    count =0; ans =0; flag=0;
    left = func(lca->left, first, count, ans , flag);
    if(!left){
        count =0; ans =0; flag=1;
        right = func(lca->right, first, count, ans, flag); 
    }
    key1 = ans;
  
    count =0; ans =0; flag=0;
    left = func(lca->left, second, count, ans , flag);
    if(!left){
        count =0; ans =0; flag=1;
        right = func(lca->right, second, count, ans, flag); 
    }
    key2 = ans;

    
    return key1+key2+1;
    
  
    
}
