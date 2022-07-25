class Solution {
public:
    char repeatedCharacter(string s) {
        
        int n = s.length() , i;
        
        map<char, int> mp;
        for(i=0;i<n;i++){
            
            if(mp.find(s[i]) != mp.end() ) {
                return s[i];   
            }
            else{
                mp[s[i]]++;                
            }            
        }
        
        return ' '; 
    }
};