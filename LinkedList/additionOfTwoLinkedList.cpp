/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second)
{
  // Code here
  struct Node *head;
 head=NULL;
  int c,sum,rem;
         if(first==NULL)
         return second;
         if(second==NULL)
         return first;
         struct Node *ptr1,*ptr2,*ptr3;
         ptr1=first;
         ptr2=second;
         c=0;
         ptr3=head;
         while(ptr1!=NULL && ptr2!=NULL)
         {
             //cout<<sum<<endl;
             sum=ptr1->data+ptr2->data+c;
             rem=sum%10;
             c=sum/10;
             if(head==NULL)
             {
                 struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
                 newnode->data=rem;
                 newnode->next=NULL;
                 head=newnode;
                 ptr3=newnode;
                 
             }
             else
             {
                 struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
                 newnode->data=rem;
                 newnode->next=NULL;
                 ptr3->next=newnode;
                 ptr3=newnode;
                 
             }
              ptr1=ptr1->next;
              ptr2=ptr2->next;
             
         }
         while(ptr1!=NULL)
         {
              struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
              sum=ptr1->data+c;
              rem=sum%10;
              c=sum/10;
              newnode->data=rem;
              newnode->next=NULL;
              ptr3->next=newnode;
              ptr3=newnode;
              ptr1=ptr1->next;
         }
         while(ptr2!=NULL)
         {
              struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
              sum=ptr2->data+c;
              rem=sum%10;
              c=sum/10;
              newnode->data=rem;
              newnode->next=NULL;
              ptr3->next=newnode;
              ptr3=newnode;
              ptr2=ptr2->next;
         }
         if(c!=0)
         {
              struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
               newnode->data=c;
               newnode->next=NULL; 
               c=0; 
               ptr3->next=newnode;
         }
          
       return head;  
}
