class Solution {
private:
    void recursiveParenthesis(int lc, int rc, int n, string str, vector<string> &ans){
        
        if(str.size() == (2*n)){
            ans.push_back(str);
            return;
        }
        
        if(lc < n){
            recursiveParenthesis(lc+1, rc,n, str += '(', ans);
            str.pop_back();    // remove while BACKTRACK ing
        }
        if( rc<lc ){           
            recursiveParenthesis(lc, rc+1, n, str += ')', ans);
            str.pop_back();    // remove while BACKTRACK ing
        }            
        
    }
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        recursiveParenthesis(0,0,n,"", ans);       
        return ans;       
        
    }
};