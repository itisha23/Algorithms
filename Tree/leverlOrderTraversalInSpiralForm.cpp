struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void printSpiral(struct Node *root);

/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

    printSpiral(root);
    cout<<endl;
  }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
void printSpiral(Node *root)
{
     if(root==NULL)
        return;
    stack<Node*>st1;
    stack<Node*>st2;
    st1.push(root);
    Node *x;
    
    while(st1.empty()!=1 || st2.empty()!=1){
        
        while(st1.empty()!=1){
        x=st1.top();
        st1.pop();
        cout<<x->data<<" ";
        if(x->right)
            st2.push(x->right);
        if(x->left)
            st2.push(x->left);
    }
    
    while(st2.empty()!=1){
        x=st2.top();
        st2.pop();
        cout<<x->data<<" ";
        if(x->left)
         st1.push(x->left);
        if(x->right)
         st1.push(x->right);
    }
        
    }
    
    
}
