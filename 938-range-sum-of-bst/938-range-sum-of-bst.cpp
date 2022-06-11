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
    int s=0;
    int sum(TreeNode* node, int min, int max){
        
        if(!node) return 0;

        if(node->val < max) sum(node->right, min, max);
        if(node->val <= max && node->val>= min) s += node->val ;
        if(node->val > min) sum(node->left, min, max);
        
        return s;    
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum(root,low,high);
    }
};