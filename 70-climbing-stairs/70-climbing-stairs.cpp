class Solution {
private:
    int fun(int n , vector<int> &dp){
        if(n <2) return 1;
        
        //MEMOIZE : STEP 2
        if(dp[n] != -1) return dp[n];
        
        int l = fun(n-1 , dp);
        int r = fun(n-2 , dp);
        
        //MEMOIZE : STEP 3. store while returning
        return dp[n] = l+r;
        
    }
public:
    int climbStairs(int n) {
        
        // NUM of distinct ways -> DP problem
        
        
        // 3 steps
        // step 1: write index
        // step 2: do all possible stuff on that index
        // step 3: sum all possible
        
        //RECURSIVE SOLN, GIVES TLE
        
        // memoize it
        // MEMOIZE : STEP 1;
        vector<int> dp(n+1 , -1);
        
        return fun(n , dp);
        
    }
};