
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of the linked list node is as
struct node
{
	int data;
	struct node* next;
};
*/
/* split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.*/
void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    node *head=source;
    
    node* slow=head;
    node *fast=head;
    node *prev;
    
    while(fast && fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    prev->next=NULL;
    *frontRef=head;
    *backRef=slow;
}
// merges two sorted list into one big list
struct node* mergeList(struct node* a, struct node* b)
{
   node *result;
   if(a==NULL)
   return b;
   if(b==NULL)
   return a;
   
   if(a->data<b->data)
   {
     result=a;
       result->next=mergeList(a->next,b);
   }
   else
   {
       result=b;
       result->next=mergeList(a,b->next);
   }
   return result;
}
