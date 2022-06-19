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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // map<vertical, map<level, multiset<nodes in that level> 
        map<int, map<int, multiset<int>>> mp;   //multiset as we need to store non-unique eles as well
        
        //     node       vertical,level
        queue<pair<TreeNode*, pair<int,int>>> q;
        
        q.push({root, {0,0}});
        
        while(!q.empty()){
            
            auto x = q.front();
            q.pop();
            
            TreeNode* node = x.first;
            int vertical = x.second.first;
            int level = x.second.second;
            
            mp[vertical][level].insert(node->val);             // put node->val in map
            
            if(node->left != NULL) q.push({node->left, {vertical-1,level+1}});
            if(node->right != NULL) q.push({node->right, {vertical+1,level+1}});            
        }
        
        vector<vector<int>> ans;
        
        for(auto p: mp){
            
            vector<int> col;
            
            for(auto it: p.second){
                
              col.insert(col.end(), it.second.begin() ,it.second.end());  //why push_back wasn't working?
            }            
            ans.emplace_back(col);
        }
        return ans;       
    }
};