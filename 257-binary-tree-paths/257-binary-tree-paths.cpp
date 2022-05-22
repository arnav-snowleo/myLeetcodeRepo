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
    void allPaths(TreeNode* root, vector<string> &ans, string str){
        
        str += to_string(root->val);
        if(root->left || root->right) str += "->";
        if(!root->left && !root->right) {
            ans.push_back(str);
        }

        if(root->left) allPaths(root->left, ans,str);
        if(root->right) allPaths(root->right, ans,str);        
        
        str.pop_back();
        str.pop_back();
       
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root && !root->left && !root->right) return {to_string(root->val)};
        
        vector<string> ans;
        allPaths(root,ans,"");
        return ans;
        
    }
};