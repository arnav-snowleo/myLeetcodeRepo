/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        
        //we cannot delete the curr ;  as previous is not given
        
        //so, we copy the next value to the curr , and then remove link from curr to next
        
        
        ListNode* temp = node;
        
        temp->val = temp->next->val; //value copy        
        temp->next = temp->next->next; //remove the link

        

        
    }
};