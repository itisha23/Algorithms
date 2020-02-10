void func(Node *root) {

    stack<Node*>st;
    Node *curr = root;

    while(1) {

        while(curr) {
            cout<<curr->data;
            curr = curr->left;
        }
        if(st.empty())
            break;
        
        x = st.front();
        st.pop();

        curr = x->right;
    }
}