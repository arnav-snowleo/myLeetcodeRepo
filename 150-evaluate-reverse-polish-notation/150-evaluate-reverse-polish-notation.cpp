class Solution {
    
private: 
    int result(string c, int x, int y){
        
        int ans = 0;
        if(c=="+") ans=  x+y;
        if(c=="-") ans= x-y;
        if(c=="/") ans= x/y;
        if(c=="*") ans= x*y;
        
        return ans;        
    }
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(int i=0;i<tokens.size();i++){
            
            if(tokens[i] == "+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                
                
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                
                    st.push(result(tokens[i], y,x));                
            }  
            else{
               st.push(stoi(tokens[i]));   
            }                     
        }
        
        return st.top();
        
    }
};