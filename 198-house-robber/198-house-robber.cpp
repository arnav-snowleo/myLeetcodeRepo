// MAXIMUM SUM OF NON-ADJACENT ELEMENTS

// TRY OUT ALL POSSIBLE WAYS -- recursion
// overlapping subproblems found -- (DP problem) -can memoize

class Solution {
private:
    int fun(int index, vector<int> &nums, vector<int> &dp){
        
        // if I am at index = 0, then index 1 is not picked // draw recur tree to visualze
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int pick = nums[index] + fun(index-2 , nums , dp);
        int not_pick = 0 + fun(index-1 , nums, dp);
        
        return dp[index] = max(pick, not_pick);     
        
    }
public:
    int rob(vector<int>& nums) {
        
        // MEMOIZE is top-down
       
        int n = nums.size();
        vector<int> dp(n+1 , -1);
        
        return fun(n-1 , nums , dp);        
    }
};


