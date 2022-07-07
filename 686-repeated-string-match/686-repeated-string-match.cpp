class Solution {
private:
    bool isSubstring(string a, string b){
        
        int m = a.length() , n = b.length();
        
        for(int i=0;i<=m-n;i++){
            
            int j;
            for(j=0;j<n;j++){
                
                if(a[i+j] != b[j]) {
                    break;
                }         
            }
            if(j==n) {        //reached end, break not executed, so b is substring of a
                return true;
            }
        }       
        return false;        
    }
public:
    int repeatedStringMatch(string a, string b) {
        
        if(a==b) return 1;
        string initial_a = a;
        
        int ans = 1;
        while(a.length() < b.length()){
            a+=initial_a;
            ans++;
        }
        
        if(isSubstring(a,b)){
            return ans;
        }
        if(isSubstring(a+initial_a,b)){
            return ans+1;
        }
        return -1;
    }
};