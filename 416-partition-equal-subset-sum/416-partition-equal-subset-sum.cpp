// MEMOIZED SOLUTION

class Solution {
private:
    bool helper(int index, int target , vector<int>& nums , vector<vector<int>>& dp){
        
        //base cases
        if(target ==0) return true;
        if(index == 0) return (nums[0] == target);
        
        if(dp[index][target] != -1) return dp[index][target];
        
        bool not_take = helper(index-1,target, nums, dp);
        bool take = false;
        if(target >= nums[index]) take = helper(index-1,target - nums[index], nums, dp);        
        
        return dp[index][target] = take || not_take;
        
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++) sum += nums[i];        
        if(sum %2 != 0) return false;        
        
        int k = sum/2; 
        //now find subset with sum k, if able to find, then there is must another subset of sum k
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return helper(n-1, k, nums, dp);       
    }
};