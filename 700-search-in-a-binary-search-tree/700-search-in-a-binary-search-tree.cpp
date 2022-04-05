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
    TreeNode* searchBST(TreeNode* root, int val) {       
        
        if(!root) return nullptr;
        
        TreeNode* node{nullptr};
        if(val == root->val) { node = root; }
        
        if(val > root->val && root->right) {node =searchBST (root->right, val);}
        if(val < root->val && root->left) {node= searchBST (root->left, val);}
        
        return node;
        
    }
};