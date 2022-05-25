class Solution {
public:
    int percentageLetter(string s, char letter) {
        
        // WITHOUT USING MAP
        
        // unordered_map<char,int> mp;
        // for(int i=0;i<s.length();i++)  mp[s[i]]++;   
        
        int count = 0;
        for(auto it: s){
            if(it == letter) count++;
        }
        
        // int x  = mp[letter];
        float y = s.length();
        
        return (100*count) / y;
    }
};