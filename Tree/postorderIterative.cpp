// take advanatge of this fact that in post order tarversal, the last node accesseed is root
//Lt Rt Root. so that means for sure, aaapne root k right child root sabse phle aayegi

void postOrder(Node *root) {

    Node *curr = root, *prev = NULL;
    stack<Node*>st;

    while (1)
    {
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }

        if(st.empty())
            break;

        x = st.front();
        if(x->right == NULL || x->right == prev) {
            cout<<x->data<<endl;
            prev = x;
            st.pop();

        } else {
            curr = x->right;
        }
    }
    
}