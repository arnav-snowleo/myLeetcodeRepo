// O(n) time complexity using one pass solution 
        
//store the minimum price <till the left of the current index we are at>
//calculate profit at each index
//store the profits and update max_profit accordingly

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX, max_profit = 0, n = prices.size();

        for(int i =0; i<n ;i++){      
            
            mini = min(mini, prices[i]);
            
            int profit = prices[i] - mini;
            max_profit = max(max_profit , profit);            
        }   
        return max_profit;    
    }
};