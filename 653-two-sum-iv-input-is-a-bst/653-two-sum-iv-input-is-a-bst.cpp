// SIMILAR QUESTION WAS ASKED IN <ITRIBE> QS1, 
// instead of BST, given sorted array.

// BRUTE:
// INORDER TRAVERSAL ON BST GIVES SORTED ARRAY.
// ON SORTED ARRAY, SOLVE TWO SUM , using two pointers


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
public:
    vector<int> arr;
    void inorder(TreeNode* node){
        
        if(!node) return;
        
        inorder(node->left);
        arr.push_back(node->val);
        inorder(node->right);

    }    
    bool findTarget(TreeNode* root, int k) {
        
        if(!root->left && !root->right) return false;
        
        inorder(root);
        
        int n = arr.size(), i=0,j=n-1;
        
        while(i<j){                               // i<j   and not i<=j        
            
            int sum = arr[i] + arr[j];
            if(sum > k){
                j--;
            }else if ( sum < k){
                i++;
            }else{
                return true;
            }
        }        
        return false;
    }
};



//subtract at root node, 
        
// if (k-root->val) < root->val ---search for remaining in left subtree
// if (k-root->val) > root->val ---search for remaining in right subtree


/*
        if(!node) return false;
        if(k==0) return true;
        // if(k<0) return false;
        
        int rem = k - node->val;
        return rem < node->val ? helper(node->left, rem) : helper(node->right, rem);
*/