#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
void sort(Node **head);
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}
// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
void sort(Node **head)
{
    Node *head_ref = *head;
    Node *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ans, *head1, *head2;
    if(head_ref==NULL|| head_ref->next== NULL)
        return;
        
    head1 = head_ref;
    head2 = head_ref->next;
    
    ptr1= head1; ptr2 = head2;
    while(ptr1 && ptr2){
        ptr1->next = ptr2->next;
        ptr1 = ptr1->next;
        if(ptr1){
            ptr2->next = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
   
    ptr4 = NULL; ptr5= head2; ptr6 = NULL;
    while(ptr5){
        ptr6 = ptr5->next;
        ptr5->next = ptr4;
        ptr4 = ptr5;
        ptr5= ptr6;
    }
    
    ptr2= ptr4;
    
    //merge ptr1 and ptr2;
    ptr1 = head1;
    ans = NULL;  ptr3= NULL;
    while(ptr1 && ptr2){
        if(ptr1->data < ptr2->data){
            if(ptr3== NULL)
            {
                ans = ptr1;
            }
            else{
                ptr3->next = ptr1;
            }
                ptr3 = ptr1;
               ptr1 = ptr1->next; 
           
        }
        else{
             if(ptr3== NULL)
            {
                ans = ptr2;
            }
            else{
                ptr3->next = ptr2;
            }
                ptr3 = ptr2;
                ptr2 = ptr2->next; 
        }
    }

    while(ptr1){
        ptr3->next = ptr1;
        ptr3 = ptr1;
        ptr1 = ptr1->next;
    }
    
    while(ptr2){
        ptr3->next = ptr2;
        ptr3 = ptr2;
        ptr2 = ptr2->next;
    }
    
    *head = ans;
   
}