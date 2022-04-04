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
    //RECURSIVE SOLUTION
    
    // << USING REVERSE PRE-ORDER >> i.e , ROOT -> RIGHT->LEFT
    
    //&res -> vector passed by reference
    void recursion(TreeNode* node, int level, vector<int> &res){
        
        if(!node) return;
        if(res.size() == level) res.push_back(node->val); //node
        
        recursion(node->right, level+1 , res);            //right
        recursion(node->left, level+1 , res);             //left        
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root , 0 , res);
        return res;        
    }
};