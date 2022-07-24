/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool helper(TreeNode* root, TreeNode* subroot){
        
        if(!root || !subroot) return root==subroot;
        
        bool left = helper(root->left , subroot->left);
        bool right = helper(root->right , subroot->right);
        
        return root->val == subroot->val && left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root && !subRoot) return true;
        if(!root) return false;
        
        return helper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};