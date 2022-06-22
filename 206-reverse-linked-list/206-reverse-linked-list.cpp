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

// USING STACK
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        stack<int> st;
        ListNode* temp = head;
        ListNode* temp2 = head;
        
        if(!temp) return NULL;
        
        while(temp){   
            
            st.push(temp->val);
            temp= temp->next;           
        }
        
        while(temp2){   
            
            temp2->val = st.top();
            st.pop();
            temp2= temp2->next;           
        }     
        
        return head;        
    }
};

// // Iterative solution
        
//         // three pointers
//         // prevPtr
//         // currPtr
//         // nextPtr

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {

//         ListNode *prevPtr = NULL;
//         ListNode *currPtr = head;
//         ListNode *nextPtr;
        
//         while(currPtr != NULL){            
            
//             nextPtr = currPtr->next; //initialise nextPtr
//             currPtr->next = prevPtr; //detach
                        
//             prevPtr = currPtr;       //update prevPtr
//             currPtr = nextPtr;       //update 
            
//             // the order of execution of the 4 lines of code is important.
            
//             //nextPtr
//             //current->next
            
//             //prevPtr
//             //currPtr           
            
//         }
//         return prevPtr;   
        
//     }
// };