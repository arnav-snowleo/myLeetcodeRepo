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
    void helper(TreeNode* root){
        
        if(!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int count =0;
        while(!q.empty()){            
            
            int n = q.size();
            vector<int> level(n);
            count++;
            for(int i=0;i<n;i++){
                
                TreeNode* node= q.front();
                q.pop();
                
                int index = (count%2 != 0) ? i : (n -i-1 );
                level[index] = node->val;
 
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
            }
            ans.push_back(level);
        }
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return {};
        helper(root);
        return ans;
    }
};

// LEVEL ORDER TRAVERSAL - { use queue,  for loop inside while loop }

// MINOR TWEAK TO level order traversal, keep count variable, 
// if count odd, inserting index is (i)
// if count even inserting index is (size-i-1)