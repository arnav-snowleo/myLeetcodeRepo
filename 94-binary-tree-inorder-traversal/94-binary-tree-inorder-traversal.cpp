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

// ITERATIVE APPROACH

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        stack<TreeNode*> st;        
        TreeNode* node = root;
        
        while(true){
            
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{
                
                if(st.empty() == true) break;
                
                node  = st.top();
                st.pop();
                
                inorder.push_back(node->val);
                node= node->right;   
            }   
        }
        return inorder;        
    }
};


// RECURSIVE APPROACH
/*

private:
    void inorderTraverse(TreeNode* root, vector<int> &inorder){
        
        if(!root) return ;
        
        if(root->left != NULL) inorderTraverse(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right != NULL) inorderTraverse(root->right, inorder);       
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int> inorder;
        inorderTraverse(root, inorder);
        return inorder;
        
    }

*/