/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL){
            return nullptr;
        }
        else if(head->next->next == NULL){
            head->next = NULL;
            return head;
        }
        else{
            //for L.L of length >= 3
            ListNode* slow = head;
            ListNode* fast = head;
            
            while(fast!= NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            //now slow is at the middle;
            //copy the content of middle's next node into middle node and detach
            //the middle's next node from the ll.
            slow->val = slow->next->val;
            slow->next = slow->next->next;          
            
        }
        return head;
        
        
    }
};