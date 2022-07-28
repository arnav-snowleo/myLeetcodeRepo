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

// BRUTE: 0(n) approach

class Solution {
    int ans(TreeNode* root){
        
        if(!root) return 0;
        
        int left=0,right=0;
        
        if(root->left) left += 1 + ans(root->left);
        if(root->right) right += 1 + ans(root->right);
        
        return left + right ;      
    }
public:
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;        
        return ans(root) + 1;
    }
};