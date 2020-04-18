/* Given two sorted non-empty linked lists. Merge them in 
such a way that the result list will be in reverse 
order. Reversing of linked list is not allowed. Also, 
extra space should be O(1) */
#include<iostream> 
using namespace std; 

/* Link list Node */
struct Node 
{ 
	int key; 
	struct Node* next; 
}; 

Node* reverse(Node *node) {
    if(node == NULL)
        return NULL;
    
    Node *ptr1 = NULL,*ptr2, *ptr3;
    ptr2 = node;
    while(ptr2) {
        ptr3 = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 =ptr3;
    }
    
    return ptr1;
}
Node *func(Node *node1, Node *node2, Node *&head) {
    
    if(node1 == NULL) {
        head = node2;
        head = reverse(head);
        return node2;
    }
    
    if(node2 == NULL) {
        head = node1;
        head = reverse(head);
        return node1;
    }
    Node *temp;
    
    if(node1->key < node2->key) {
        temp = func(node1->next, node2, head);
        temp->next = node1;
        return node1;
    } else {
        temp = func(node1, node2->next, head);
        temp->next = node2;
         return node2;
        
    }
}

Node* SortedMerge(Node *a, Node *b) 
{ 
	Node *head = NULL, *x;
    x = func(a, b, head);
    x->next = NULL;
    return head;
} 

/* Function to print Nodes in a given linked list */
void printList(struct Node *Node) 
{ 
	while (Node!=NULL) 
	{ 
		cout << Node->key << " "; 
		Node = Node->next; 
	} 
} 

/* Utility function to create a new node with 
given key */
Node *newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* res = NULL; 

	/* Let us create two sorted linked lists to test 
	the above functions. Created lists shall be 
		a: 5->10->15 
		b: 2->3->20 */
	Node *a = newNode(5); 
	// a->next = newNode(10); 
	// a->next->next = newNode(15); 

	Node *b = newNode(2); 
	b->next = newNode(3); 
	//b->next->next = newNode(20); 

	cout << "List A before merge: \n"; 
	printList(a); 

	cout << "\nList B before merge: \n"; 
	printList(b); 

	/* merge 2 increasing order LLs in descresing order */
	res = SortedMerge(a, b); 


	cout << "\nMerged Linked List is: \n"; 
	printList(res); 

	return 0; 
}
