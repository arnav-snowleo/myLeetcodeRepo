class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;
        
        map<char ,int> mp;        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        map<char ,int> mp2;        
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        
        for(int i =0;i<mp.size();i++){
            
            if(mp[i] != mp2[i]) return false;
        }
        
        return true;
    }
};