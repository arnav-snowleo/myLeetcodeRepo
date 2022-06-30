// MEMOIZED SOLUTION

// TC : O(N*2*3)

// index, buy, cap --three states --3d dp
// used 2d dp earlier - wrong

class Solution {
private: 
    int helper(int index,int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int cap){
        
        if(index == prices.size() || cap==0) return 0; 
        
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];    
        
        int profit = 0;
        if(buy){ // allowed to buy           
            int x = -prices[index] + helper(index+1, 0, prices, dp, cap);    //buy
            int y =                + helper(index+1, 1, prices, dp, cap);    //not buy
                
            profit = max(x,y);    
            
        }else{ //allowed to sell
            
            int x = prices[index] + helper(index+1, 1, prices, dp, cap-1);   //sell 
            int y =               + helper(index+1, 0, prices, dp, cap);     //not sell
                
            profit = max(x,y);  
        }
        
        return dp[index][buy][cap] =  profit;           
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)));
        return helper(0,1,prices,dp,2);
    }
};