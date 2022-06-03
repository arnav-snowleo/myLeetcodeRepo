// INORDER TRAVERSAL
// SORTS THE TREE VAL IN ASCENDING ORDER

// TC: O(n) for recur traversal 
// SPACE OPTIMIZED APPROACH-> keep a counter decrement it everytime
// SC: O(1) 

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
    void inorder(TreeNode* root , int &k){   // notice &k here

        if(!root ) return ;       

        inorder(root->left,k);
        
        k --;
        
        if(k==0) ans = root->val;

        inorder(root->right,k);        
    }
public:
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k); 
        return ans;       
    }
};

