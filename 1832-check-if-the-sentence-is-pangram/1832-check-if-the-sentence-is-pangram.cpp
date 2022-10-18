class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int len = sentence.length();
        set<char> st;
        for(int i=0;i<len;i++)            
            st.insert(sentence[i]); 
        
        string all = "abcdefghijklmnopqrstuvwxyz";
        set<char> st2;
        for(int i=0;i<all.length();i++)            
            st2.insert(all[i]); 
        
        return st == st2 ;        
    }
};