class Solution {
public:
    int percentageLetter(string s, char letter) {
        
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)  mp[s[i]]++;       
        
        int x  = mp[letter];
        float y = s.length();
        
        return (100*x) / y;
    }
};