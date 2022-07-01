// MEMOIZED APPROACH:

// take, not_take
// but here, infinite supplies
// so slight change to take, not_take

class Solution {
private:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>> &dp){
        
        //BASE CASE
        if(amount == 0 ) return 0;
        if(amount<0 || index == coins.size()) return INT_MAX-1;

        if(dp[index][amount] != -1) return dp[index][amount];
        
        int take = INT_MAX-1;
        if(coins[index] <= amount)  take = 1 + helper(index,amount-coins[index], coins, dp); 
                                                  // (index+1) we didn't do as we can take that again
        
        int not_take = helper(index+1,amount , coins, dp);             
              
        
        return dp[index][amount] = min(take,not_take);     
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount==0) return 0;
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1,-1));
        int ans = helper(0,amount, coins,dp);
        
        return ans == INT_MAX-1 ? -1 : ans;
        
    }
};


// DP STATES
// index, amount
