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
    ListNode* middleNode(ListNode* head) {
        
        // use two jump pointers
        
        // SLOW-- pointer moves 1 step at a time
        // FAST-- pointer moves 2 steps at a time
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
       
        
        // && beacause if any of the condition is true, do not enter, 
        while(ptr2 != NULL && ptr2->next != NULL){
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            
        }       
        return ptr1; //return the slow pointer        
    }
};