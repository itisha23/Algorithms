/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
void merge(Node *root1, Node *root2)
{
    stack<Node*>st1;
    stack<Node*>st2;
    
    struct Node* curr1=root1,*ptr;
    struct Node *curr2=root2;
    
    while(1)
    {
       
            while(curr1!=NULL)
            {
                st1.push(curr1);
                curr1=curr1->left;
            }
             while(curr2!=NULL)
            {
                st2.push(curr2);
                curr2=curr2->left;
            }
            
            if(st1.size()!=0 && st2.size()!=0)
            {
                if(st1.top()->data<st2.top()->data)
                {
                   // cout<<st1.top()<<" "<<st2.top()<<endl;
                    ptr=st1.top();
                    cout<<ptr->data<<" ";
                    st1.pop();
                    curr1=ptr->right;
                }
                else
                {
                    ptr=st2.top();
                    cout<<ptr->data<<" ";
                    st2.pop();
                    curr2=ptr->right;
                }
            }
            else if(st1.size()!=0)
            {
                ptr=st1.top();
                cout<<ptr->data<<" ";
                st1.pop();
                curr1=ptr->right;
            }
            else if(st2.size()!=0)
            {
                ptr=st2.top();
                cout<<ptr->data<<" ";
                st2.pop();
                curr2=ptr->right;
            }
            else
             break;
            
    }
    
}
