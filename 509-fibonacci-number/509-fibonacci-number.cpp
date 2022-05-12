class Solution {
private:
    int recursiveFib(int n, vector<int> &dp){
        if(n<= 1) return n;
        
        //STEP 2. check if val updated in dp vector, else retuurn -1
        if(dp[n] != -1) return dp[n];
        
        
        //STEP 3.   store in dp[n] 
        return dp[n] = recursiveFib(n-1 , dp) + recursiveFib(n-2, dp);
    }
public:
    int fib(int n) {
        
        //DP SOLUTION USING MEMOIZATION
        //STEP 1. INITIALIZATION
        vector<int> dp(n+1,-1);
        
        
        return recursiveFib(n , dp);
        
    }
};