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
    
    int height(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        // definition of balanced binary tree
        if(abs(lh-rh) > 1) return -1;
        // if the definition is violated somewhere, it will make the lh || rh as -1
        if(lh == -1 || rh==-1) return -1;
        
        return max(lh,rh) + 1;   
        
    }
    bool isBalanced(TreeNode* root) { 
        
        return height(root) != -1;        
        
    }
};