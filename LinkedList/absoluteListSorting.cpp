void sortList(Node **head_ref)
{
   if(*head_ref==NULL)
   return;
   struct Node *ptr=*head_ref;  
   struct Node *ptr1,*prev,*ptr2;
    while(ptr!=NULL)
   {
      if(ptr->data<0 && ptr!=*head_ref)
      {
         prev->next=ptr->next;
         ptr2=ptr;
         ptr=ptr->next;
         ptr2->next=*head_ref;
         *head_ref=ptr2;
         
      }
      else
      {prev=ptr;
      ptr=ptr->next;
      
      }
   }
}
© 2019 GitHub, Inc.
