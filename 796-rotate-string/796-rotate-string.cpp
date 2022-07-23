class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int m = s.length(), n = goal.length();
        if(m!=n) return false;
        
        for(int i=0;i<m;i++){
            
            s+= s[0];
            s.erase(0,1);                        //0th index, 1 ele
            
            if(s==goal) return true;           
        }       
        return false;        
    }
};