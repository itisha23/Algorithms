/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
void dfs(Node *root, int count, int &ans) {
    if(root == NULL){
        return;
    }
    ans = max(ans, count);
    
    for(int i=0; i<root->children.size(); i++) {
       dfs(root->children[i], count+1, ans); 
    }
}
class Solution {
public:
    int maxDepth(Node* root) {
        
        if(root == NULL){
            return 0;
        }
        int ans =0;
        int count=1;
        dfs(root, count, ans);
        return ans;
    }
};

