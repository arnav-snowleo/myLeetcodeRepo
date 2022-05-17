class Solution {
public:
    int strStr(string haystack, string needle) {  

        int h = haystack.length();    
                
        if(h<needle.length()) return -1;
        if(haystack==needle) return 0;
        
        for(int i=0;i<h;i++){
            
            if(haystack[i] == needle[0] && haystack.substr(i , needle.length()) == needle ) return i;
 
        }
        return -1;   
    }
};