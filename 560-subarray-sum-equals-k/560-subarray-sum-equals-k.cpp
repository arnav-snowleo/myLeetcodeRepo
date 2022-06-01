// PREFIX sum, HASHMAP
// sum is key in map
// sum occurence is value in map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count =0,sum=0, n = nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            sum += nums[i];          
            
            if(sum==k) count++;
            if(mp.find(sum - k) != mp.end()) count+= mp[sum-k]; 
            
            mp[sum]++;           
        }
        return count;        
    }
};