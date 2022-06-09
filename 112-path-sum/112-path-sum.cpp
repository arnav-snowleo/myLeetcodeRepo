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
public:
    bool ans = false;
    void helper(TreeNode* node, int k, int num){
        
        if(!node) return;      
        
        num += node->val;
        if( !node->left && !node->right && num==k){
            ans = true;
            return;           
        }
        
        helper(node->left, k, num);
        helper(node->right, k, num); 
        
    }    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) return false;
        
        helper(root, targetSum, 0);
        return ans;
    }
};
