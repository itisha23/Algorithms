
Node *construct(int index, int min, int max, int pre[], int n) {

    if(index >= n )
        return NULL;
    
    if(pre[index] <= min || pre[index]  >= max)
        return NULL;

    Node *newnode  = (Node*)malloc(sizeof(Node));
    newnode->data = pre[index];

    index++;

    newnode ->left = construct(index, min, newnode->data, pre, n);
    newnode ->right = construct(index, newnode->data, max, pre, n);


    return newnode;
}