// MEMOIZED APPROACH:

class Solution {
private:
    int helper(int index, int buy, vector<int>& prices, vector<vector<int>> &dp){
        
        if(index == prices.size()) return 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        int profit = 0;
        
        if(buy){
            int x = -prices[index] + helper(index+1, 0, prices, dp);
            int y =                  helper(index+1, 1, prices, dp);
            
            profit = max(x,y);
        }else{
            int x =  prices[index];
            if(index<prices.size()-2) x+= helper(index+2, 1, prices, dp);
            int y =        helper(index+1, 0, prices, dp);
            
            profit = max(x,y);
        }
        
        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return helper(0,1,prices,dp);        
    }
};
