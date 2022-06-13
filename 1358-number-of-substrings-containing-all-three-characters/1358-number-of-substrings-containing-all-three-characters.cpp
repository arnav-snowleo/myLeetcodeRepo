// SLIDING WINDOW

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int result =0,counter=0,i=0,j=0, n= s.length();   
        
        vector<int> count = {0,0,0};        
        
        while(j<n){
      
            count[s[j]-'a']++;                         // hashmap or counter
            
                                                       // but we write breaking condition 
            while(count[0] && count[1] && count[2]){   // atleast one of them is asked
                counter++;

                count[s[i]-'a']--;
                i++;
            }

            result += counter;                         // why this ? 
            j++;
        }
        return result;       
    }
};