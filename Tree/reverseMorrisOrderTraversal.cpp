while (curr != NULL) { 
   
        if (curr->right == NULL) { 
            cout<<curr->data;
            curr = curr->left; 
        } 
  
        else { 
  
            // find inorder successor of current Node 
            Node* succ = curr->right; 
  
            while (succ->left != NULL && succ->left != curr) 
                succ = succ->left; 
  
            if (succ->left == NULL) {
                succ->left = curr;
                curr = curr->right; 
            } 
            else { 
  
                succ->left = NULL; 
  
                if (++count == k) 
                    Klargest = curr;
                curr = curr->left; 
            } 
        } 
    } 
