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
    ListNode* reverseList(ListNode* head) {
        
        // Iterative solution
        
        // three pointers
        // prevPtr
        // currPtr
        // nextPtr

        ListNode *prevPtr = NULL;
        ListNode *currPtr = head;
        ListNode *nextPtr;
        
        while(currPtr != NULL){            
            
            nextPtr = currPtr->next; //initialise nextPtr
            currPtr->next = prevPtr; //detach
                        
            prevPtr = currPtr;       //update prevPtr
            currPtr = nextPtr;       //update 
            
            // the order of execution of the 4 lines of code is important.
            
            //nextPtr
            //current->next
            
            //prevPtr
            //currPtr           
            
        }
        return prevPtr;   
        
    }
};