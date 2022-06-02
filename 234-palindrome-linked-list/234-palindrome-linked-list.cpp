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
    bool isPalindrome(ListNode* head) {

        string str = "";
        ListNode* temp = head;        
        
        while(temp){
            str+= to_string(temp->val);
            temp = temp->next;
        }
        
        string s = str;        
        reverse(str.begin(), str.end());
        
        return s == str;
    }
};