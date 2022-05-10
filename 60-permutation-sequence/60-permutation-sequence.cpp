class Solution {
public:
    string getPermutation(int n, int k) {
        
        // FOR OA, use the inbuilt next_permutation 

        string str = "";        
        for(int i=0;i<n;i++){
            str += to_string(i+1);
        }
        
        int count = 0;
        
        vector<string> st;
        do{
          st.push_back( str );  
          count++;
        }while(count<k && next_permutation( str.begin() , str.end() ));        


        return st[st.size()-1];
        
    }
};