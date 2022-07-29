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

// OPTIMISED: 0((logn)^2)
class Solution {
private:
    int findHeight(TreeNode* node, bool left){
        
        int height =0;
        
        while(node){
            height++;
            if(left) node = node->left;
            else node = node->right;            
        }
        
        return height;                
    }
public:
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int left_subtree_height = findHeight(root, true);
        int right_subtree_height = findHeight(root, false);
        
        if(left_subtree_height == right_subtree_height) return (1<<left_subtree_height) - 1;                                                                         // 1<< right_subtree_height will aslo work
        // this is 2 power height (i.e num of nodes in complete BT of height h)
        
        
        return 1 + countNodes(root->left) + countNodes(root->right);               
    }
};






/*
// BRUTE: 0(n) approach

class Solution {
    int ans(TreeNode* root){
        
        if(!root) return 0;
        
        int left=0,right=0;
        
        if(root->left) left += 1 + ans(root->left);
        if(root->right) right += 1 + ans(root->right);
        
        return left + right ;      
    }
public:
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;        
        return ans(root) + 1;
    }
};
*/