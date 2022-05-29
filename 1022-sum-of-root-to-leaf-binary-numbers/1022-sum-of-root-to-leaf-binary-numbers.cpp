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
    int sum =0;
    
    void helper(TreeNode* root, string str){       
        
        str += to_string(root->val);
        if(!root->left && !root->right) sum += stoi(str, 0, 2);        
        
        if(root->left) helper(root->left , str );
        if(root->right) helper(root->right , str );
        
        str.pop_back();                //remove while backtracking
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        helper(root , "");
        return sum;
    }
};