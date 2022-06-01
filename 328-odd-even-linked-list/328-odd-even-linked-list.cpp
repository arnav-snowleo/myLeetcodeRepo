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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL) return head; 
        
        ListNode* firstEven = head->next;
        ListNode* odd = head;
        ListNode* even = firstEven;

        while(odd->next != NULL  && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;           
            even = even->next;
        }
        
        odd->next = firstEven;
        // if(even->next != NULL) 
        if(even != NULL && even->next != NULL) even->next = nullptr;
        
        return head;

    }
};