/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
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
