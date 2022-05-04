class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        //USE MAP
        
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            mp[nums[i]]++;
        }
        
        for(auto it: mp){
            
            if(it.second>1){
                ans.push_back(it.first);
            }
        }       
        return ans;       
        
        
        
        // SORT
        // XOR
        
//         vector<int> ans;
//         int n = nums.size();
        
//         sort(nums.begin() , nums.end());
        
//         for(int i=0;i<n-1;i++){
            
//             if( (nums[i]^nums[i+1]) ==0 ){
//                 ans.push_back(nums[i]);
//             }
            
//         }
//         return ans;
        
    }
};