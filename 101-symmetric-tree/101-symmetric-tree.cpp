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
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        return isSymmetricHelper(root->left , root->right);
        
    }
    
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        
        //BASE CASES
        if(!left || !right) return left == right;
        if(left->val != right->val) return false;
        
        //LEFT SUBTREE
        //preorder traversal
        bool  l = isSymmetricHelper(left->left , right->right);
        
        //RIGHT SUBTREE
        //reverse pre-order traversal
        bool  r = isSymmetricHelper(left->right , right->left);       
        
        //JOIN
        return l && r;
    }
};