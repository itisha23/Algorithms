//https://leetcode.com/problems/validate-binary-search-tree
// Works only for positive numbers

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool funcUtil(TreeNode *root,int lower,int upper){
        
        if(root == NULL)
            return true;
        int val=root->val;
        
        if(lower!=-1 && val<=lower)
            return false;
        if(upper!=-1 && val>=upper)
            return false;
        
        return funcUtil(root->left,lower,val) && funcUtil(root->right,val,upper);
        
    }
    bool isValidBST(TreeNode* root) {
        
        return funcUtil(root,-1,-1);
        
    }
};
