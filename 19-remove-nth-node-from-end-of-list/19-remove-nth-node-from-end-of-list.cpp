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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        ListNode* temp = head;
        if(temp->next == NULL){
            if(n==1){
                temp = NULL;
                return temp;
            }
        }
        
        if(temp->next->next == NULL){
            if(n==1){
                temp->next = NULL;
                return temp;
            }
            if(n==2){
                temp = temp->next;
                return temp;
            }
        }
        else{       

        //for getting length of linkedlist
        ListNode* temp = head;
        int count = 0;
        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }        
        cout<<"count is"<<count;
        if((count+1)==n){
            head = head->next;
        }    
        int x = (count-n);        
        
        //for deleting
        ListNode* temp2 = head;
        int count2 = 0;
        
        while(temp2 && temp2->next){
            if(count2 == x){
                temp2->next = temp2->next->next;
            }
            count2++;
            temp2 = temp2->next;           

        }   
        
        // return head;              
              
        }
        return head;
               
    }
};