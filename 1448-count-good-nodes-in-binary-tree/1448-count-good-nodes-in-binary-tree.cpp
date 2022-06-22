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
    void helper(TreeNode* node, int maxi,int &count){
        
        if(!node) return;
        
        if(node->val >= maxi) {
            maxi = node->val;    //update maxi
            count++;
        }
        
        helper(node->left, maxi,count);
        helper(node->right, maxi,count);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        int c =0;
        helper(root,root->val,c); 
        return c;        
    }
};