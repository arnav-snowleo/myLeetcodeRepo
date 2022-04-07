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
        
    void helper(TreeNode* node){
        
        TreeNode* temp = new TreeNode();
        
        if(!node) return;
        
        temp = node->left;
        node->left = node->right;
        node->right = temp;   
        
        // RECURSION
        if(node->left) helper(node->left);
        if(node->right) helper(node->right);
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        // empty tree
        if(!root) return nullptr;
        
        helper(root);
        return root;
        
    }
}; 