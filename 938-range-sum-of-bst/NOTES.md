​
Range Sum of BST
​
if(node->val < max) sum(node->right, min, max);
if(node->val <= max && node->val>= min) s += node->val ;
if(node->val > min) sum(node->left, min, max);