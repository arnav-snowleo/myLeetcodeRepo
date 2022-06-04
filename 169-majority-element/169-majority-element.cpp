//  MOST OPTIMIZED APPROACH   - MOORE'S VOTING ALGO

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int candidate = 0;        
        
        for(auto it: nums){
            
            if(count ==0) candidate = it;
            if(candidate == it) count++;
            if(candidate != it) count--;
        }      
        
        return candidate;       
    }
};



// BRUE APPROACH, USE HASHMAPS
/*
        int ceilVal = ceil(nums.size()/2);        
        int ans = 0;        

        unordered_map<int,int> mp; 
        
        for (int i =0;i<nums.size();i++){
            mp[nums[i]]++;      
        }
        
        for(auto it : mp){
            
            if(it.second > ceilVal){
                return it.first;
            }
        }        
        return ans;   
*/