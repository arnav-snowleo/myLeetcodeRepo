class Solution {
public:
    bool checkRecord(string s) {
        
        if(s.length() == 1 ) return true;
        
        
        int a = 0, l =0 , p=0 ;
        for (int i=0;i<s.length();i++){
            
            if(s[i] == 'A'){
                a++;
            }else if(s[i] == 'P'){
                p++;
            }
        }
                     
        for (int i=0;i<s.length()-2;i++){
            
           if(s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L'){
                l++;
               break ;
               
            }
        }

        if(a<2 && l == 0){
           return true;
        }
        return false;
        
    }
};