class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> st;
        
        for(int i=0;i<ops.size();i++){
            
            if(ops[i] == "+"){
                int x  = st.top();
                st.pop();
                int y = st.top();
                int z = x+y;
                st.push(x);
                st.push(z);
                
            }
            else if(ops[i] == "C"){
                st.pop();
            }
            else if(ops[i] == "D"){
                int x = st.top();
                st.push(2*x);
                
            }else{
                st.push(stoi(ops[i]));
            }
            
        }
        
        int sum =0;
        while(!st.empty()){
            int x = st.top();
            sum += x;
            st.pop();
            
        }

        
        return sum;
        
    }
};