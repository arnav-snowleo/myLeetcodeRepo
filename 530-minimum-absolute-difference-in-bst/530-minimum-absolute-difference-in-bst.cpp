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

// INORDER TRAVERSAL IN A BST RETURNS ELEMENTS IN SORTED ORDER

class Solution {
private:
    void inorderTraverse(TreeNode* root, vector<int> &arr){
        
        if(!root) return;
        
        inorderTraverse(root->left, arr);
        arr.push_back(root->val);
        inorderTraverse(root->right, arr);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        inorderTraverse(root,arr);
        
        int n = arr.size();
        int mini = INT_MAX;
        for(int i=0;i<n-1;i++){
            mini = min(mini, abs(arr[i]-arr[i+1]));
        }
        return mini;
    }
};