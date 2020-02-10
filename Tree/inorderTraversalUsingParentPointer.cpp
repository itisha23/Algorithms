// 45: 34: 04
// 10.2.20

// 1. Initialize current node as root
// 2. Initialize a flag: leftdone = false;
// 3. Do following while root is not NULL
//      a) If leftdone is false, set current node as leftmost
//         child of node. 
//      b) Mark leftdone as true and print current node.
//      c) If right child of current nodes exists, set current
//         as right child and set leftdone as false.
//      d) Else If parent exists, If current node is left child
//         of its parent, set current node as parent. 
//         If current node is right child, keep moving to ancestors
//         using parent pointer while current node is right child
//         of its parent.  
//     //  e) Else break (We have reached back to root)

// At last is my impelementattion

// C++ program to print inorder traversal of a Binary Search 
// Tree (BST) without recursion and stack 
#include <bits/stdc++.h> 
using namespace std; 

// BST Node 
struct Node 
{ 
	Node *left, *right, *parent; 
	int key; 
}; 

// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->parent = temp->left = temp->right = NULL; 
	return temp; 
} 



/* A utility function to insert a new node with 
given key in BST */
Node *insert(Node *node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
	{ 
		node->left = insert(node->left, key); 
		node->left->parent = node; 
	} 
	else if (key > node->key) 
	{ 
		node->right = insert(node->right, key); 
		node->right->parent = node; 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Function to print inorder traversal using parent 
// pointer 
void inorder(Node *root) 
{ 
	bool leftdone = false; 

	// Start traversal from root 
	while (root) 
	{ 
		// If left child is not traversed, find the 
		// leftmost child 
		if (!leftdone) 
		{ 
			while (root->left) 
				root = root->left; 
		} 

		// Print root's data 
		printf("%d ", root->key); 

		// Mark left as done 
		leftdone = true; 

		// If right child exists 
		if (root->right) 
		{ 
			leftdone = false; 
			root = root->right; 
		} 

		// If right child doesn't exist, move to parent 
		else if (root->parent) 
		{ 
			// If this node is right child of its parent, 
			// visit parent's parent first 
			while (root->parent && 
				root == root->parent->right) 
				root = root->parent; 
			if (!root->parent) 
				break; 
			root = root->parent; 
		} 
		else break; 
	} 
} 

int main(void) 
{ 
	Node * root = NULL; 

	root = insert(root, 24); 
	root = insert(root, 27); 
	root = insert(root, 29); 
	root = insert(root, 34); 
	root = insert(root, 14); 
	root = insert(root, 4); 
	root = insert(root, 10); 
	root = insert(root, 22); 
	root = insert(root, 13); 
	root = insert(root, 3); 
	root = insert(root, 2); 
	root = insert(root, 6); 

	printf("Inorder traversal is \n"); 
	inorder(root); 

	return 0; 
} 

void func(Node *root) {

    Node *curr = root;
    int leftdone = false;

    while(curr) {

        if(curr->left != NULL && leftdone == false){
            curr = curr->left;
        }

        while(curr->left == NULL || leftdone == true){
            cout<<curr ->key<<" ";

            if(curr ->right) {
                curr = curr->right;
                leftdone = false;
            } else {
                leftdone = true;
                Node *parent  = curr->parent;
                 if(parent && parent ->left == curr){
                     curr = parent;
                 } else {
                     while(parent && parent->right == curr) {
                         curr = parent;
                         parent = curr->parent;
                     }
                 }
                 curr = parent;
            }
        }
    }
}