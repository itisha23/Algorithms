#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node*left;
    char data;
    struct node *right;
};


multimap<int,char>mp;
map<int,char>m,mp2;

void hori(struct node *root,int horiz)
{
   if(root==NULL)
    return;
   mp.insert(make_pair(horiz,root->data));
   hori(root->left,horiz-1);
   hori(root->right,horiz+1);
}

void levelorder(struct node *root)
{
   queue<struct node *>q;int i=0;
   if(root==NULL)
     return;
   q.push(root);
   while(q.empty()!=1)
   {
      struct node *ptr=q.front();
      q.pop();
     m[i]=ptr->data;
     i++;
    if(ptr->left!=NULL)
    q.push(ptr->left);
    if(ptr->right!=NULL)
    q.push(ptr->right);
     
    }


}
struct node *create(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int search(char cvalue)
{
   map<int,char>::iterator it1;
   for(it1=m.begin();it1!=m.end();it1++)
   {
     if(it1->second==cvalue)
        return it1->first;
   }
 
}

int main()
{
    int horiz=0;int hvalue;char cvalue;int min,index;
    struct node *root;
    /*root=create('a');
    root->left= create('b');
    root->right= create('c');
    root->left->left  = create('d');
    root->left->right = create('e'); 
    root->left->left->left=create('l');
    root->right->left=create('f');
    root->right->left->left=create('h');
    root->right->right=create('g');
    root->right->left->right=create('i');
    root->right->left->right->right=create('j');
    root->right->left->right->right->right=create('k');*/

    root=create('a');
    root->left=create('b');
    root->left->right=create('c');
    root->left->right->right=create('d');
    root->left->right->right->right=create('e');
    root->right=create('f');
   
    

   
    hori(root,0);
    levelorder(root);
    multimap<int,char>::iterator it;
    it=mp.begin();
    
    hvalue=it->first;
    cvalue=it->second;
    min=search(cvalue);
    
    for(it=mp.begin();it!=mp.end();it++)
      {
          if(it->first==hvalue)
          {
            index=search(it->second);
            if(index<min)
               cvalue=it->second;
          }
         
          else
          {
            mp2.insert(make_pair(hvalue,cvalue));
            hvalue=it->first;
            cvalue=it->second;
            min=search(cvalue);
          }
      }
         mp2.insert(make_pair(hvalue,cvalue));
map<int,char>::iterator it2;
for(it2=mp2.begin();it2!=mp2.end();it2++)
  cout<<it2->second<<" ";	
	    
}
