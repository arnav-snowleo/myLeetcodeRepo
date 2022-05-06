class Solution {
public:
    string removeDuplicates(string s) {
        
        if(s.length() == 1) return s;
        if(s.length() == 2 && s[0]==s[1]) return "";

        string ans;        
        stack<char> st;
        for(int i=0;i<s.length();i++){              
            
            if(st.empty()){                
                st.push(s[i]); 
            }            
            else{                
                if(st.top() == s[i]){
                    st.pop();                    
                }else{
                    st.push(s[i]);
                }                
            }                            
        }
        
        while(!st.empty()){
            
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};