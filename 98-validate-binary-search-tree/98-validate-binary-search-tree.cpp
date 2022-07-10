// BST ------ THINK OF INORDER TRAVERSAL

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
    void inorder(vector<int> &arr,TreeNode* node){
        
        if(!node) return;
        
        //INORDER TRAVERSAL
        
        inorder(arr, node->left);
        arr.push_back(node->val);
        inorder(arr, node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> arr;
        inorder(arr, root);
        int n = arr.size();
        
        for(int i=0;i<n-1;i++){
            
            if(arr[i]>=arr[i+1]) return false;
            
        }
        return true;
        
        
    }
};