class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        // 1. if # is the first char of string
        // 2. backspacing an empty text, the text will continue empty.
        // 3. if after putting chars in stack,, both stack size different, different strings
        
        stack<char> st1;
        stack<char> st2;
        
        for(int i =0;i<s.length();i++){
            
            if(s[i] == '#' ) {        
                
                if(!st1.empty())  st1.pop();                
            }
            else {st1.push(s[i]);}
        }
        
        for(int j=0;j<t.length();j++){
            
            if(t[j] == '#') {
                
                if(!st2.empty())  st2.pop();                
            }
            else{st2.push(t[j]);   }        
        }
        
        if(st1.size() != st2.size()) {return false;}
        if(st1.size() == st2.size()){
            
            if(st1.empty() && st2.empty()) {return true;}
            
            while(!st1.empty() && !st2.empty()){                
                if(st1.top() == st2.top()){
                    st1.pop();
                    st2.pop();
                }
                else{                    
                    return false;
                    break;
                }
            }           
        }
        return true;
        
    }
};