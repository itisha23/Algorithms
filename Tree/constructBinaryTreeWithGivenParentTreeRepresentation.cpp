    the constructed binary tree. */
Node *createTree(int parent[], int n)
{
   Node*root=NULL;
   int i;
   if(n==0)
        return root;
    Node *par [n];
    for(i=0;i<n;i++)
        par[i]=NULL;
    
    for(i=0;i<n;i++){
        if(par[i]==NULL){
            Node* newnode = (Node*)malloc(sizeof(Node));
            newnode->data=i;
            newnode->left=NULL;
            newnode->right=NULL;
            par[i]=newnode;
        }
        
        if(parent[i]==-1){
            root=par[i];
        }
        else{
            if(par[parent[i]]==NULL){
                Node* newnode = (Node*)malloc(sizeof(Node));
                newnode->data=parent[i];
                newnode->left=NULL;
                newnode->right=NULL;
                par[parent[i]]=newnode;
            }
            if(par[parent[i]]->left==NULL){
                par[parent[i]]->left = par[i];
            }
            else{
                par[parent[i]]->right = par[i];
            }
        }
    }
    return root;
}
