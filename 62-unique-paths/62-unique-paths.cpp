// MEMOIZED SOLUTION

class Solution {
private:
    int pathsCounter(int i, int j, vector<vector<int>> &dp){
        
        //base case
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = pathsCounter(i,j-1 , dp);
        int up = pathsCounter(i-1,j , dp);        
        
        return dp[i][j] = left + up;       
        
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        
        return pathsCounter(m-1,n-1 , dp);
        
    }
};


// explore all ways - recursion
// found overlapping subproblems in recursive tree - USE DP


//STEP 1
// write in terms of index

//STEP 2
// do all possible stuffs on index

//STEP 3
// sum || min || max ->whatever asked in qs