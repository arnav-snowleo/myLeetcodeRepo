// SPACE OPTIMIZED

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
        
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
        
        // if(index==0){
        //     return amount % coins[index] == 0 ;
        // };  
        
        for(int cap=0;cap<=amount;cap++){
            prev[cap] = ( cap % coins[0]==0 );
        }
        
        for(int index =1 ;index<n;index++){
            
            for(int cap=0;cap<=amount;cap++){
                
                int not_take = prev[cap];
                int take = 0;        
                if(coins[index] <= cap) take = curr[cap - coins[index]];               
                
                curr[cap] = take+not_take;
            }            
            prev = curr;         //switch
        }        
        return prev[amount];     //where you are at after two for loops executed   
    }
};