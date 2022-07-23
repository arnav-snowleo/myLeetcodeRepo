class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if(strs.size()==0 || strs.size()==1) return {strs};  // size0, size1        
        
        map< string , vector<string> > mp;                   // CHOOSING THE DATATYPE
        
        int n = strs.size();
        for(int i=0;i<n;i++){
            
            string key = strs[i];
            sort(key.begin() , key.end());
            
            mp[key].push_back(strs[i]); 
            
            //key is the sorted string and the pushed value is the original string
          
        }        
        
        vector<vector<string>> ans;
        for(auto it: mp){
            
            ans.push_back(it.second);            
        }        
        return ans;        
    }
};