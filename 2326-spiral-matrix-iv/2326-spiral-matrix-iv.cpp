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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix(m , vector<int>(n,-1));
        
        int minrow =0;
        int mincol =0;
        int maxrow =m-1;
        int maxcol =n-1;
        
        ListNode* temp = head;
        
        //TRAVERSAL
        while(temp!=NULL && minrow<=maxrow && mincol <=maxcol){
            
            //TOP WALL
            for(int i=minrow;i<=maxcol;i++){
                if(temp) matrix[minrow][i] = temp->val;
                if(temp) temp = temp->next;
            }
            minrow++;
            
            //RIGHT WALL
            for(int i=minrow;i<=maxrow;i++){
                if(temp) matrix[i][maxcol] = temp->val;
                if(temp) temp = temp->next;
            }
            maxcol--;
            
            //BOTTOM WALL
            for(int i=maxcol;i>=mincol;i--){
                if(temp) matrix[maxrow][i] = temp->val;
                if(temp) temp = temp->next;
            }
            maxrow--;
            
            //LEFT WALL
            for(int i=maxrow;i>=minrow;i--){
                if(temp) matrix[i][mincol] = temp->val; 
                if(temp) temp = temp->next;
            }
            mincol++;            
        }        
        return matrix;        
    }
};