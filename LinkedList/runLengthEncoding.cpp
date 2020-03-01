Node *runLength(Node *head){
    if(head == NULL)
        return NULL;

    ptr = head;

    prev = NULL;

    while(ptr){

        count = 1;
        while(ptr->next && ptr->next->data == ptr->data ) {
            ptr= ptr->next;
            count++;
        }

        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->data = ptr->data;

        if(prev == NULL){
            head = newnode;
        } else{
            prev->next = newnode;
           
        }
         prev = newnode;
         if(count>1) {
             Node *newnode2 = (Node*)malloc(sizeof(Node));
             newnode2->data = count;
             prev->next = newnode2;
             prev = newnode2;
         }

         ptr = ptr->next;
    }
}