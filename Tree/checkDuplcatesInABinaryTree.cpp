/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/
/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
string func(Node *node,map<string,int>&mp)
{
    string s="",lstr,rstr;
    if(node==NULL)
    return s+"&";
    lstr=func(node->left,mp);
    rstr=func(node->right,mp);
    
    s=s+node->data+lstr+rstr;
    if(mp.count(s))
    mp[s]++;
    else
    mp[s]=1;
    return s;
}  
bool dupSub(Node *root)
{
    string str;
   if(root==NULL)
    return false;
  map<string,int>mp;
  string s=func(root,mp);
  map<string,int>::iterator it;
   //  for(it=mp.begin();it!=mp.end();it++)
    //cout<<it->first<<" "<<it->second<<" "<<it->first.size()<<endl;
  for(it=mp.begin();it!=mp.end();it++)
    if(it->second>1)
    {
        str=it->first;
        // We check for greater than 3 beacuse size of single character will be minimum 3(d&&).if subtrees size 2 then also
        //minimum of 5 charcaters  are needed and id subtree's size is 3 then 7  charcters are needed and we ned duplicates 
        // subtree of atleast 2 in size not just a single node we're talking about.
        if(str.size()>3)
        return true;
    }
  return false;
}
