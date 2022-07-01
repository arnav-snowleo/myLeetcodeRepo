// MEMOIZED APPROACH

// dp states
// index, amount

class Solution {
private:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>> &dp){
        
        if(amount ==0) return 1;
        if(amount<0 || index == coins.size()) return 0;
        
        if(dp[index][amount] != -1) return dp[index][amount];
        
        int take = 0;        
        if(coins[index] <= amount) take = helper(index, amount - coins[index], coins, dp);
        
        int not_take = helper(index+1, amount, coins, dp);
        
        return dp[index][amount] = take + not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1 , -1));
        return helper(0,amount, coins, dp);
    }
};


