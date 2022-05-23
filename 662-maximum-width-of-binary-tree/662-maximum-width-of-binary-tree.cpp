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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        queue<pair<TreeNode* , long long int>> q;
        q.push({root,0});
        
        int ans = 0;
        while(!q.empty()){
            int mini = q.front().second;            
            int leftmost,rightmost;   
            int size = q.size();
            
            for(int i=0;i<size;i++){
                long long int cur_id = q.front().second - mini;  //subtracting and starting the cur_id from 0, in each level to avoid overflow
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i==0) leftmost = cur_id;
                if(i==size-1) rightmost = cur_id;
                
                if(node->left) q.push({node->left, cur_id*2+1});
                if(node->right) q.push({node->right, cur_id*2+2});                
                
            }           
            ans = max(ans , rightmost -leftmost +1);
        }
        return ans;        
    }
};