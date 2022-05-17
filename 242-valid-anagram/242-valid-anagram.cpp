class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // APPROACH 2
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s==t ;
        
        // APPRAOCH 1
//         if(s.length() != t.length()) return false;
        
//         map<char ,int> mp1 , mp2;        
//         for(int i=0;i<s.length();i++){
//             mp1[s[i]]++;
//             mp2[t[i]]++;
//         }
        
//         return mp1 == mp2 ? true : false;  // compare both maps 
    }
};