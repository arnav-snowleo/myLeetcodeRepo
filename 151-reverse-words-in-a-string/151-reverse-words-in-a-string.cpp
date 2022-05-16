class Solution {
public:
    string reverseWords(string s) {
                
        stack<string> st;                

        for(int i=0;i<s.length();i++){    
            string str = "";
            while(s[i] != ' ' && i< s.length() ){
                str += s[i];
                i++;
            }
            
            if(str.length() != 0) st.push(str);  // takes care of leading spaces
           
        }
        
        
        string ans = "";
        while(!st.empty()){
            
            if(st.size() == 1) { 
                ans += st.top();
            }
            else{
                ans+=st.top() + ' ';
            }                
            st.pop();
        }
        return ans;
        
    }
};
