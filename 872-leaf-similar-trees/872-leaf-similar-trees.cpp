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
    void setLeafArray(TreeNode* root, vector<int> &arr){

        if(!root->left && !root->right) arr.push_back(root->val);        
        
        if(root->left) setLeafArray(root->left, arr);
        if(root->right) setLeafArray(root->right, arr);
        
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        
        vector<int> arr1;
        vector<int> arr2;
        
        setLeafArray(root1 , arr1);        
        setLeafArray(root2 , arr2);
         
        return arr1 == arr2;
    }
};