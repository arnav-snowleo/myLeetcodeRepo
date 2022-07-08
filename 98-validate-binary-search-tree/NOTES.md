bool isValidHelper(TreeNode* node, long long int start , long long int end){
​
if(!node) return true;
if(node->val >=end || node->val <=start) return false;
return isValidHelper(node->left , start , node->val)
&& isValidHelper(node->right , node->val, end);
}