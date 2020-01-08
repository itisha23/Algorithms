
#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	int data; 
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
	int len = sizeof(in) / sizeof(in[0]); 
	node* root = buildTree(in, pre, 0, len - 1); 
	printInorder(root); 
} 

