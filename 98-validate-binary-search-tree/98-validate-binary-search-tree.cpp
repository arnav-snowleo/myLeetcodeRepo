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
    bool isValidHelper(TreeNode* node, long long int start , long long int end){

        if(!node) return true;        
        if(node->val >=end || node->val <=start) return false; // CHECK IF NODE->VALUE IS IN RANGE
        
        return isValidHelper(node->left , start , node->val)
            && isValidHelper(node->right , node->val, end);    
    } 
    
    bool isValidBST(TreeNode* root) {
        
        // case not considered earlier [2,2,2]            -> just equality add  -> silly mistake
        
        // also [5,4,6,null,null,3,7] case not considered -> introduce range    -> needed clarity -> do a dry run of sample cases

        
        // [2147483647]                                    -> INT_MAX & upper range equal -> use LLONG->MAX

        return isValidHelper(root, LLONG_MIN, LLONG_MAX);
    }
}; 