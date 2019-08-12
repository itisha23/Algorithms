void func(Node* &node, Node* &prev){
    if(node == NULL)
     return;
     
    func(node->right,prev);
    if(prev){
        node->data = node->data+prev->data;
        
    }
    prev=node;
    func(node->left,prev);
}

void modify(Node **root)
{
  Node *prev = NULL;
  func(*root,prev);
}

