// MAXIMUM SUM OF NON-ADJACENT ELEMENTS

// TRY OUT ALL POSSIBLE WAYS -- recursion
// overlapping subproblems found -- (DP problem) - can memoize
//                                               - tabulation -> (index-1 , index-2) present --space optimize

class Solution {
public:
    int rob(vector<int>& nums) {
        
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
};