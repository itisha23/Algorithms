void func(Node* root, vector<int>vec,int k){
    if(!root)
        return;
        
    vec.push_back(root->data);
    func(root->left,vec,k);
    func(root->right,vec,k);
    
    int sum=0,i,j;
    for(i=vec.size();i>=0;i--){
        sum+=vec[i];
        if(sum==k){
            for(j=0;j<=i;j++){
                cout<<vec[j]<<" ";
            }
            cout<<endl;
        }
    }
    vec.pop_back();
}
int printCount(Node *root,int k)
{
        vector<int>vec;
        func(root,vec,k);
}
