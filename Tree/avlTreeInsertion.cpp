#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    int height;
}

struct node* Getnewnode(int key){

    struct node* newnode=(node*)malloc(sizeof(struct node));
    node->data = key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;

    return newnode;
}

int height(node *node){
    if(!node)
        return 0;
    return node->height;
}

int balance(node *node){
    if(!node)
        return 0;
    return height(node->left) - height(node>right);
}

node *rightRotate(node *node){
    
    node *x= node->left->right;
    node->left->right = node;
    node->left = x;

    node->height = max(height(node->left),height(node->right))+1;
    node->left->height =  max(height(node->left->left),height(node->left->right))+1;

    return node->left;
}

node *leftRotate(node *node){
    
   node *x = node->right->left;
   node->right->left = node;
   node->right = x;

   node->height = max(height(node->left),height(node->right))+1;
   node->right->height =  max(height(node->right->left),height(node->right->right))+1;

   return node->right;
}

node* insert(node* root,int key){
    if(root==NULL){
        return Getnewnode(key);
    }

    if(key<root->data){
        root->left = insert(root->left,key);
    }

    else if(key>root->data){
        root->right = insert(root->right,key);
    }

    else{
        //Handles equal value case
        return root;
    }

    int bf = balance(root);

    // LL case
    if(bf >1 && key<root->left->data){
        return rightRotate(root);
    }

    //RR case
    if(bf<1 && key>root->right->data){
        return leftRotate(root);
    }

    //LR case
    if(bf > 1 && key>root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //RL case
    if(bf <1 && key<root->right->data){
        root->right = rightRoatate(root);
        return leftRotate(root);
    }

    return root;
    
}
int main(){

    struct node* root;
    
    for(i=1;i<n;i++){
        cin>>key;
        root = insert(root,x);
    }
}