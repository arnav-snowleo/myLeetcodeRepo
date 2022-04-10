class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ceilVal = ceil(nums.size()/2);        
        int ans = 0;        
        
        // map<int, int> mp;
        
        unordered_map<int,int> mp; // use an unordered_map for better T(0)
        
        for (int i =0;i<nums.size();i++){
            mp[nums[i]]++;      
        }
        
        for(auto it : mp){
            
            if(it.second > ceilVal){
                ans = it.first;
            }
        }        
        return ans;   
        
    }
};