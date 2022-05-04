class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // O(n) time complexxity using one pass solution 
        
        //store the minimum price and check in loop for profit        
        //store the profits and update max_profit accordingly
        
        int mini = INT_MAX;
        int n = prices.size();
        int profit,max_profit = 0;
        
        for(int i =0; i<n ;i++){      
            
            mini = min(mini, prices[i]);
            
            profit = prices[i] - mini;
            max_profit = max(max_profit , profit);
            
        }   

        return max_profit;    
        
        //two loops -> O(n*n) solution
    }
};