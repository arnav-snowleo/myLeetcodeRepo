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
    vector<int> ans; 
    
    // RECURSIVE SOLUTION
    // SOLVE USING ITERATIVE METHOD
     
    void preorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        
        preorder(root);
        return ans;  
        
    }
};