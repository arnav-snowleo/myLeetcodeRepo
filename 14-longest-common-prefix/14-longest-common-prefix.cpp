// 2 for loops

// BRUTE:  < Take the first string > compare it with the remaining strings
// TC: O(m*n) , SC: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        
        for(int i=0;i<strs[0].length();i++){   
            
            char ch = strs[0][i];
            
            bool match = true;
            
            for(int j=1;j<strs.size();j++){
                
                if(strs[j][i] != ch || strs[j].size() < i){
                    match = false;
                    break;
                }         
            } 
            
            if(match != false){
                ans +=ch;
            }else break;
        }
        return ans;       
    }
};