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

        return (!root) || isSymmetricHelper(root->left , root->right);
        
    }
    
    bool isSymmetricHelper(TreeNode* root1, TreeNode* root2){
        
        //BASE CASE
        if(!root1 || !root2) return root1 == root2;
        
        //preorder traversal simultaneously
        bool  l = isSymmetricHelper(root1->left , root2->right);
        bool  r = isSymmetricHelper(root1->right , root2->left);       
        
        //JOIN
        return (root1->val == root2->val) && l && r;
    }
};