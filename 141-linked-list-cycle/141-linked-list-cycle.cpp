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
    bool hasCycle(ListNode *head) {
        
        ListNode* temp = head;
        if(temp==NULL || temp->next == NULL){
            //zero node or only one node
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        bool hasCycle = false;           
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        return hasCycle;
    }
};