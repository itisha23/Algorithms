
#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	char data; 
	node* left; 
	node* right; 
}; 

void printInorder(node* node) 
{ 
	if (node == NULL) 
		return; 

	
	printInorder(node->left);
    cout<<node->data<<" "; 
	printInorder(node->right); 
} 



int main() 
{ 
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 


	printInorder(root); 
} 

int search(int in[], int key, int low, int high) {
    
    int i;
    
    for(i=low; i<=high; i++){
        if(in[i] == key)
            return i;
    }
}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    
    if (inStrt > inEnd)
        return NULL;
    
    int index = search(in, pre[preIndex], inStrt, inEnd);
    Node * newnode = (Node*)malloc(sizeof(Node));
    newnode->left = NULL; 
    newnode->right= NULL;
    newnode ->data = pre[preIndex];
    preIndex++;

    
    newnode ->left = buildTree(in, pre, inStrt, index-1);
    newnode ->right = buildTree(in, pre, index+1, inEnd);
    
    return newnode;

// For a single tese case uyou can even use static variable.

//Optimisation is we can store the elements in unordered map in C++ so that search can be done in O(1) time

unordered_map<int, int> buildMap(int  in[]){

    unordered_map<int, int>mp;

    for(i=0; i<size; i++)
        map[in[i]] =i;
}

// now just access map instead of searching in buildTreeCode;
=======
// For a single tese case uyou can even use static variable.
