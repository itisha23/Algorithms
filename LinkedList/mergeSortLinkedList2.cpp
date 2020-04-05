Node *sortedMerge(Node *a, Node *b) {
    
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
        
    Node *result;
    if(a->data < b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
} 
Node *func(Node *head, Node *tail) {
    if(head ==  NULL || head == tail)
        return head;
        
    Node *slow = head; Node *fast = head, *mid, *head2, *prev;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    mid = slow; 

    prev->next = NULL; // Important Point to note here is that for two nodes, this should not run into a infinite loop . so it's imp to call fom mid; and not after mid
    
    head = func(head, prev);
    
    head2 = func(mid, tail);
    
    head = sortedMerge(head, head2);
   
    
    return head;
}
Node* mergeSort(Node* head) {
    // your code he
    
    Node *ptr = head;
    while(ptr->next) {
        ptr = ptr->next;
    }
    
    return func(head, ptr);
}