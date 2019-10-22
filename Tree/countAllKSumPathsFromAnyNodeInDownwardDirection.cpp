void func(Node* root, vector<int>vec,int k,int &count){
    if(!root)
        return;
        
    vec.push_back(root->data);
    func(root->left,vec,k,count);
    func(root->right,vec,k,count);
    
    int sum=0,i;
    for(i=vec.size()-1;i>=0;i--){
        sum+=vec[i];
        if(sum==k){
           count++;
        }
    }
    vec.pop_back();
}
int printCount(Node *root,int k)
{
        vector<int>vec;
        int count=0;
        func(root,vec,k,count);
        return count;
}
