// MEMOIZED APPROACH: 

// just pay transacton fee when a transaction is complete

// changing DP STATES: 
// index , buy<0,1> 

class Solution {
private:
    int helper(int index, int buy, int fee, vector<int>& prices, vector<vector<int>> &dp){

        if(index == prices.size()) return 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        int profit = 0;
        
        if(buy){
            
            int x = -prices[index] + helper(index+1, 0, fee, prices, dp);  //buy
            int y =                  helper(index+1, 1, fee, prices, dp);  //dont buy
            
            profit = max(x,y);
        }else{
            int x =  -fee + prices[index] + helper(index+1, 1, fee, prices, dp);  //sell
            int y =                         helper(index+1, 0, fee, prices, dp);  //dont sell
            
            profit = max(x,y);         
        }        
        return dp[index][buy] = profit;       
    }
public:
    int maxProfit(vector<int>& prices, int fee) {        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        return helper(0,1,fee,prices,dp);        
    }
};
