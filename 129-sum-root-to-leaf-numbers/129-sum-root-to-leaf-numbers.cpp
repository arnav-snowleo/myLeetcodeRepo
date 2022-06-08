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


// BRUTE using, vector to store. and then iterate, then sum up and return

// OPTIMIZED, removed vector to store, convert on the fly, and sum up
class Solution {
public:
    int sum =0;
    void insertNumbers(TreeNode* node, string str){
        
        if(node == NULL) return;
        
        if(node->left == NULL && node->right == NULL ) {
            str += to_string(node->val);
            int num = stoi(str);
            sum += num;
        }      
        
        insertNumbers(node->left , str +to_string(node->val));
        insertNumbers(node->right, str +to_string(node->val));        
    }
public:
    int sumNumbers(TreeNode* root) {

        insertNumbers(root, "");
        return sum;
    }
};