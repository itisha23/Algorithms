// There is no need to keep a level in bottom view since you always have to replace anywys.

void func(Node *node,int count,map<int,int>&mp)
{
    if(node==NULL)
    return;
    //mp.insert(make_pair(count,node->data));
    mp[count]=node->data;
    func(node->left,count-1,mp);
    func(node->right,count+1,mp);
}
void bottomView(Node *root)
{
   // Your Code Here
    map<int,int>mp;
    int x=0;
     func(root,x,mp);
     map<int,int>::iterator it;
     for(it=mp.begin();it!=mp.end();it++)
    cout<<it->second<<" ";
}