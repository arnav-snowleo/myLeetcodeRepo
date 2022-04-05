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
    // TRY TO IMPROVE SOLUTION
    bool checker(TreeNode* root, int x){
        
        if(!root) return true;
        if(root->val != x) return false;
        
        bool leftCheck = checker(root->left , x);
        bool rightCheck = checker(root->right , x);
        
        return leftCheck && rightCheck;
        
    }
    
    bool isUnivalTree(TreeNode* root) {       
        return checker(root,root->val);
    }
};  