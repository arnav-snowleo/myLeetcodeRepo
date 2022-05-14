// all possible ways we need to explore -> RECURSION

class Solution {
private:
    int fun(vector<int>& nums) {
        
        // TABULATION APPROACH - bottom up
       
        int n = nums.size();
        int dp[n+1];        
        dp[0] = nums[0];       
        
        for(int i=1;i<n;i++){
            
            int pick = nums[i] ;            
            if(i>1) pick += dp[i-2];
            int not_pick = 0+ dp[i-1];
            
            dp[i] = max(pick, not_pick);
        }
        
        return dp[n-1];        
    }
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> dp1;          //from index 1 (excluding 0th index) to last index
        vector<int> dp2;          //from 0th index to last but 1 index (excluding last index)
        
        for(int i=0;i<n;i++){
            
            if(i != 0 ) dp1.push_back(nums[i]);
            if(i != n-1 ) dp2.push_back(nums[i]);    
            
        }
        
        return max( fun(dp1),fun(dp2) );
     
    }
};