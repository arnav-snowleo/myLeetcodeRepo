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
    void inorderTraverse(TreeNode* root, vector<int> &inorder){
        
        if(!root) return ;
        
        if(root->left != NULL) inorderTraverse(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right != NULL) inorderTraverse(root->right, inorder);       
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int> inorder;
        inorderTraverse(root, inorder);
        return inorder;
        
    }
};