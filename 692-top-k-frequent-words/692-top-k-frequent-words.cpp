class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // using map automatically will put in lexicographical order
        
        map<string, int> mp;                
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        vector<string> ans;    
        
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        
        int count = 0;

        for(int j =maxi;j>0 ;j--){

            for(auto it: mp){
                    
                if(it.second == j){
                    count++;
                    if(count <=k) ans.push_back(it.first);
                }
            }                
        }
        return ans;        
        
        
    }
};