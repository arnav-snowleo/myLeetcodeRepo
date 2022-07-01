// TABULATION APPROACH: bottom up

// dp states
// index, amount

// base case  -- similar to memoized base condition

// dp states will be in for loop
// copy recureence from memoizationinside the for loop

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,0));
        
        // if(index==0){
        //     return amount % coins[index] == 0 ;
        // };  
        
        for(int cap=0;cap<=amount;cap++){
            dp[0][cap] = ( cap % coins[0]==0 );
        }
        
        for(int index =1 ;index<n;index++){
            
            for(int cap=0;cap<=amount;cap++){
                
                int not_take = dp[index-1][cap];
                int take = 0;        
                if(coins[index] <= cap) take = dp[index][cap - coins[index]];               
                
                dp[index][cap] = take+not_take;
            }
        }        
        return dp[n-1][amount];     //where you are at after two for loops executed   
    }
};