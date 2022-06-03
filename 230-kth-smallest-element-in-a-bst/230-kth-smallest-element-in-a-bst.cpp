// INORDER TRAVERSAL
// SORTS THE TREE VAL IN ASCENDING ORDER

// TC: O(n) for recur traversal 
// SC: O(n) for storage vector
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
    void inorder(TreeNode* root ,vector<int> &nums){

        if(!root ) return ;

        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> nums;
        inorder(root,nums);
        return nums[k-1];        
    }
};

