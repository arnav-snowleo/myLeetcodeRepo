class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp , mp2;
        int m = s.length(), i;
        
        for(i=0;i <m;i++){
            
            if(mp.find(s[i]) == mp.end()  && mp2.find(t[i]) == mp2.end()  ){
                //not mapped
                
                mp[s[i]] = t[i];        //map 
                mp2[t[i]] = s[i];
            }else{
                //mapped
                
                if(mp[s[i]] != t[i] || mp2[t[i]] != s[i]) return false;   // already mapped, check for same value
                
                // ex:  "foo"  "bar"   , 1st o is mapped to a , 
                // 2nd incoming o checks if o is mapped to r or not 
            }
        }
        return true;
    }
};


// failed for

// "badc"
// "baba"

// do reverse mapping for this