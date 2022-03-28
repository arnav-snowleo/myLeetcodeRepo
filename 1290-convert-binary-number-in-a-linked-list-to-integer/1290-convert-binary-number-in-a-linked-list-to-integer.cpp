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
    int getDecimalValue(ListNode* head) {
        
        ListNode* temp = head;
        
        if(temp &&temp->next ==NULL){
            return temp->val;
        }
        
        int count = 0;
        while(temp && temp->next){
            temp = temp->next;
            count++;            
        }
        
        int ans = 0;
        while(head ){
           
            ans += pow(2,count)*(head->val);
            head = head->next;
            
            count--;       
            
        }
        
        return ans;     
        
    }
};