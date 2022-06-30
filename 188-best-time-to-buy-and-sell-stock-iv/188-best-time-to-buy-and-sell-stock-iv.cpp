// MEMOIZED APPROACH: 

class Solution {
private:
    int helper(int index, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){

        if(index == prices.size() || cap==0) return 0;
        
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        
        int profit = 0;
        if(buy){  //allowed to buy only
            
            int x = -prices[index] + helper(index+1, 0, cap, prices, dp); //buy 
            int y =                  helper(index+1, 1, cap, prices, dp); //dint buy
            
            profit = max(x,y);
            
        }else{    //allowed to sell only
            
            int x = prices[index] + helper(index+1, 1, cap-1, prices, dp); //sold
            int y =                 helper(index+1, 0, cap, prices, dp);   //dint sell
            
            profit = max(x,y);
        }
        
        return dp[index][buy][cap] = profit;       
    }    
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2, vector<int>(k+1,-1)));
        
        return helper(0, 1, k, prices, dp);
        
    }
};