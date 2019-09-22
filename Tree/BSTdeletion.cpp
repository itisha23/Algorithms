#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node *left;
    node *right;
}

node* deleteNode(node* root, int key){

    if(root==NULL){
        return root;
    }

    if(key<root->data){
        root->left= deleteNode(root->let,key);
    }

    else if(key>root->right){
        root->right = deleteNode(root->right,key);
    }

    else{

        //one child
        if(root->left==NULL){
            node *temp = root->right;
            free(node);
            return temp;
        }

        else if(root->right==NULL){
            node *temp = root->left;
            free(node);
            return temp;
        }

        else{
            //get inorder successor. since its right child is not null, it means you can inorder successor by silple method

            node* succ= node->right;
            while(succ->left!=NULL){
                succ= succ->left;
            }

            node->data = succ->data;

            node->right = deleteNode(node->right,succ->data);
        }
    }

    return node;
}

int main(){

    //suppose you have  a BST , now you want to delete a  node, 

    struct node* root = deleteNode(root,key);
}
