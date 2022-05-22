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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //RECURSIVE APPROACH
        
        //if found p, return p
        //if found q, return q        
        if(root->val == p->val || root->val ==q->val) return root;
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        if(root->left) left = lowestCommonAncestor(root->left, p , q);
        if(root->right) right = lowestCommonAncestor(root->right, p , q);
        
        if(left && right) return root;           //both returns        
        return (left==NULL) ? right : left;      //only one returns
        
    }
};

//visualize by drawing recursive tree