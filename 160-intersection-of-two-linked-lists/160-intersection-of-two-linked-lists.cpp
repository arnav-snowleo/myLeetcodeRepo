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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
       
        ListNode* tempA = headA;
        int countA = 0;
        
        ListNode* intersectionNode = nullptr;
        
        
        // WHAT I WAS DOING WRONG
        
        //using tempA both for difference and then in incrementing
        //actally, tempA is already incremented to last node while doing countA
        //use headA in incrementing now
        
        
        
        while(tempA){
            tempA = tempA->next;
            countA++;
        }       
        
        
        ListNode* tempB = headB;
        int countB = 0;
        while(tempB){
            tempB = tempB->next;
            countB++;
        }
        
        int diff = abs(countA-countB);
        
        if(countA>countB){
            while(diff){
                headA = headA->next;
                diff--;
            }
        }else if(countA<countB){
            while(diff){
                headB = headB->next;
                diff--;
            }
            
        }else{
            //countA == countB 
            //do nothing
        }
        
        while(headA && headB){
            if(headA == headB){
                intersectionNode = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;            
        }
        
 
        return intersectionNode;
        
    }
};