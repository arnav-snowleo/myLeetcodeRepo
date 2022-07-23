class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int ans = 0;        
        for(char ch: columnTitle){
            
            int x = ch - 'A' + 1;
            ans = ans*26 + x;
        }       
        
        return ans;   
    }
};