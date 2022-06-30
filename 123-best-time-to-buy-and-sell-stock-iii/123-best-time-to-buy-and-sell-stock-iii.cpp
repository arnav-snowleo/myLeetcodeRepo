// TABULATION : space optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        
        vector<vector<int>> after(2, vector<int> (3,0));
        vector<vector<int>> curr(2, vector<int> (3,0));

        for(int index =n-1;index>=0;index--){
            
            for(int buy=0; buy<=1;buy++){
                
                for(int cap=1;cap<=2;cap++){  // CAP CAN START FROM 1, as for cap 0, ans is 0
                    
                    int profit = 0;
                    if(buy){ // can buy         
                        int x = -prices[index] + after[0][cap];    //buys
                        int y =                  after[1][cap];    //not buys
                
                        profit = max(x,y);    
            
                    }else{ //can sell
                         int x = prices[index] + after[1][cap-1];  //sells
                         int y =                 after[0][cap];    //not sells
                
                         profit = max(x,y);  
                    }             
                    
                    curr[buy][cap] = profit;
                }
            }
            
            after = curr;            
        }        
        return after[1][2];  // retutn curr[1][2] also works
    }
};


// // TABULATION SOLUTION

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        
//         //WRITING base case is not needed as we initialised in declaration itself to 0 
        
// //         // BASE CASE FOR (cap==0)
// //         for(int index=0;index<n;index++){
            
// //             for(int buy=0;buy<2;buy++){
                
// //                 dp[index][buy][0] = 0;
// //             }
// //         } 
        
// //         // BASE CASE FOR (index==n)
// //         for(int cap=0;cap<3;cap++){
            
// //             for(int buy=0;buy<2;buy++){
                
// //                 dp[n][buy][cap] = 0;
// //             }
// //         } 

//         for(int index =n-1;index>=0;index--){
            
//             for(int buy=0; buy<=1;buy++){
                
//                 for(int cap=1;cap<=2;cap++){  // CAP CAN START FROM 1, as for cap 0, ans is 0
                    
//                     int profit = 0;
//                     if(buy){ // allowed to buy           
//                         int x = -prices[index] + dp[index+1][0][cap];    //buy
//                         int y =                + dp[index+1][1][cap];    //not buy
                
//                         profit = max(x,y);    
            
//                     }else{ //allowed to sell
            
//                          int x = prices[index] + dp[index+1][1][cap-1];  //sell 
//                          int y =               + dp[index+1][0][cap];    //not sell
                
//                          profit = max(x,y);  
//                     }             
                    
//                     dp[index][buy][cap] = profit;
//                 }
//             }
//         }
        
//         return dp[0][1][2];
//     }
// };



// MEMOIZED SOLUTION

/*
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
*/