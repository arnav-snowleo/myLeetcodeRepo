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
    int sum  = 0;  //ddeclare sum globally and not in helper function, to avoid re-initialization
    
    int helper(TreeNode* root){
        if(!root) return 0;
 
        if(root && root->left && !(root->left->left) && !(root->left->right)) sum += root->left->val;

        int l = helper(root->left);
        int r = helper(root->right);

        return sum;       
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {

        int x = helper(root);
        return x;        
    }
};