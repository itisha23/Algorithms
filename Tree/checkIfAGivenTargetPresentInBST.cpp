int t2Sum(node* root, int k) {
    
    stack<node*>s1;
    stack<node*>s2;
    
    node* curr1,*curr2,*ptr1,*ptr2;
    
    s1.push(root);curr1=root;
    s2.push(root);curr2=root;
    
    while(1)
    {
        while(curr1!=NULL)
        {
            s1.push(curr1);
            curr1=curr1->left;
        }
        while(curr2!=NULL)
        {
            s2.push(curr2);
            curr2=curr2->right;
        }
        
        if(s1.empty()!=1 && s2.empty()!=1)
        {
            ptr1=s1.top();
            ptr2=s2.top();
            
            if(ptr1==ptr2||(ptr1->val>ptr2->val))
            break;
            
            if(ptr1->val+ptr2->val==k)
            {
                return 1;
            }
            else if(ptr1->val+ptr2->val<k)
            {
                s1.pop();
              curr1=ptr1->right;
            }
            else 
            {
                s2.pop();
                curr2=ptr2->left;
            }
        }
        else
         break;
    }
    return 0;
}

bool isPairPresent(struct node *root, int target)
{
    int a=t2Sum(root,target);
    if(a)
    return true;
    return false;
}
