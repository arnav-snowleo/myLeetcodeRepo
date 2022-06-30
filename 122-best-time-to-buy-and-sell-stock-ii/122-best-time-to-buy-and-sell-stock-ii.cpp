// TABULATION SOLUTION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = 0, dp[n][1] = 0;
        
        for(int index=n-1;index>=0;index--){
            
            for(int buy =0;buy<=1;buy++){
                
                int profit = 0;
                
                if(buy){
                //can buy
            
                    int x = -prices[index] + dp[index+1][0];  //buys          ,can't buy next
                    int y =                + dp[index+1][1];  //does not buy  ,can buy next  
            
                profit = max(x,y);
            
                }else{
                    //can sell only           
            
                    int x = prices[index] + dp[index+1][1];  //sells          ,can buy next
                    int y =               + dp[index+1][0];  //does not sell  ,can't buy next 
            
                    profit = max(x,y);
            
                }     
                
                dp[index][buy] = profit;
            }            
        }
        return dp[0][1];
    }
};


//RECURSIVE MEMOIZED SOLUTION

// class Solution {
// private:
//     int helper(int index, int buy, vector<int> &prices,  vector<vector<int>> &dp){
        
//         if(index == prices.size()) return 0;
        
//         if(dp[index][buy] != -1) return dp[index][buy];
        
//         int profit = 0;
//         if(buy){
//             //can buy
            
//             int x = -prices[index] + helper(index+1, 0, prices, dp);  //buys          ,can't buy next
//             int y =                + helper(index+1, 1, prices, dp);  //does not buy  ,can buy next
            
//             profit = max(x,y);
            
//         }else{
//             //can sell only           
            
//             int x = prices[index] + helper(index+1, 1, prices, dp);   //sells          ,can buy next
//             int y =               + helper(index+1, 0, prices, dp);  //does not sell  ,can't buy next 
            
//             profit = max(x,y);
            
//         }       
//         return dp[index][buy] = profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
        
//         int size = prices.size();
//         vector<vector<int>> dp(size, vector<int>(2, -1));
//         return helper(0,1, prices , dp);        
//     }
// };









// iterative solution : accepted 
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int total_profit =0, n= prices.size(),mini=INT_MAX,max_profit=0;
            
        for(int i=0;i<n;i++){
            
            mini = min(mini, prices[i]);
            
            int profit = prices[i] - mini;
            max_profit = max(max_profit, profit);
            
            if(max_profit >0) total_profit += max_profit;
            
            //once profit>0 got, reset
            if(profit>0){
                mini = prices[i];   // mini = INT_MAX will be wrong, e.g, test case [1,2,3,4,5]
                max_profit =0;
            }           
        }
        
        return total_profit;
    }
};
*/