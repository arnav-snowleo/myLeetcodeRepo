// TABULATION APPROACH: 

class Solution {   
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
         
        //base case not req as                                          here initialised 0
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2, vector<int>(k+1, 0)));

        // for loops FOR DIFFERENT STATES,  copy recurrence relation inside for loop

        
        for(int index = n-1;index>=0;index--){
            
            for(int buy =0;buy<2;buy++){
                
                for(int cap=1;cap<=k;cap++){  // MISTAKE ALERT : CAP SHOULD START FROM 1, 
                    
                    int profit = 0;
                    
                    if(buy){
                        int x = -prices[index] + dp[index+1][0][cap] ; //buy 
                        int y =                  dp[index+1][1][cap] ; //dint buy
            
                        profit = max(x,y);
                    }else{
                        int a = prices[index] + dp[index+1][1][cap-1] ; //sold
                        int b =                 dp[index+1][0][cap] ;   //dint sell
            
                        profit = max(a,b);   
                    }                   
                    dp[index][buy][cap] = profit;                     
                }
            }
        }        
        return dp[0][1][k];        
    }
};