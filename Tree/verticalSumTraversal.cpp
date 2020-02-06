


void verticalSumUtil(Node *node, int hd, 
					map<int, int> &Map) { 
	
	if (node == NULL) return; 

	
	verticalSumUtil(node->left, hd-1, Map); 


	Map[hd] += node->data; 


	verticalSumUtil(node->right, hd+1, Map); 
} 


void verticalSum(Node *root) 
{ 
	
	map < int, int> Map; 
	map < int, int> :: iterator it; 


	verticalSumUtil(root, 0, Map); 

	
	for (it = Map.begin(); it != Map.end(); ++it) 
	{ 
		cout << it->first << ": "
			<< it->second << endl; 
	} 
} 

// Method2: Space optimised solution
// Doubly linked list which uses n nodes, where n is the number of vertical lines, but I am confused here since map also has the numbe rof nodes which are equal to the number of vertical lines

void func(node * root, treeNode *head) {

    if(root == NULL)
        return;

    head ->data + = root->data;

    if(root->left) {

        if(head->left == NULL) {
            treeNode * node = (treeNode*)malloc(sizeof(treeNode));
            node ->data = 0;
            node->prev = NULL; node ->next = head;
        }
        func(root->left, head->prev);
    }

    if(root->right) {

        if(head->right == NULL) {
            treeNode *node = (treeNode*)malloc(sizeof(treeNode));
            node->data = 0; 
            node->prev = NULL; node->next = NULL;
        }
        func(root->right, head->next);
    }
}