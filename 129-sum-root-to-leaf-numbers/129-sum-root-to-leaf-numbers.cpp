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

class Solution {
public:
    // int sum =0;
    void insertNumbers(TreeNode* node, vector<string> &arr, string str){
        
        if(node == NULL) return;
        str += to_string(node->val);
        
        if(node->left == NULL && node->right == NULL ) {
            // str += to_string(node->val);
            // int num = stoi(str);
            // sum += num;
            arr.push_back(str);
        }      
        
        insertNumbers(node->left, arr , str);
        insertNumbers(node->right, arr, str);   
        
        str.pop_back();        
    }
public:
    int sumNumbers(TreeNode* root) {
        
        // if(root && !root->left && root->right) return root->val; // this was causing issue
        
        vector<string> array;
        insertNumbers(root ,array, "");

        int sum =0;
        for(auto it: array){
            sum += stoi(it);
        }
        return sum;
    }
};