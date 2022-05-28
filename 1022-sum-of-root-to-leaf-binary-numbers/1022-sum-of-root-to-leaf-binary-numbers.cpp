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
    vector<string> arr;
    
    void helper(TreeNode* root, string str){       
        
        str += to_string(root->val);
        if(!root->left && !root->right) arr.push_back(str);
        
        if(root->left) helper(root->left , str );
        if(root->right) helper(root->right , str );
        
        str.pop_back();                //remove while backtracking
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        helper(root , "");
        
        int sum=0;
        for(int i=0; i<arr.size();i++){
            sum += stoi(arr[i], 0, 2);
        }
        return sum;
    }
};