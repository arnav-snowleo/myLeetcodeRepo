class Solution {
public:
    int strStr(string haystack, string needle) {   
        
        int h = haystack.length();
        int n = needle.length();
        
        for(int i=0;i<h;i++){
            
            int j = 0 ;
            for( ; j<n && (i+j) < h;j++){
                
                if(haystack[i+j] == needle[j])
                     continue;
                break;
                
            }
            if(j == n){
                return i;
            }            
        }        
        return -1;        
    }
};