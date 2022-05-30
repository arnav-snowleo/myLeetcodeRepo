//MEMOIZED APPROACH

class Solution {
public:
    int helper(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp ){
        
        if(j<0 ||j>= grid.size()) return (+1e9);
        if(i==0) return grid[i][j];        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=0;k<grid.size();k++){
            if(k!=j) {
                mini = min(mini , helper(i-1, k, grid, dp));
            }   
        }
        return dp[i][j] = mini + grid[i][j];        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n==1) return grid[0][0];
        vector<vector<int>> dp(n , vector<int>(n,-1));
        
        int mini = INT_MAX;
        for(int j=0;j<n;j++){
            int ans = helper(n-1,j,grid,dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};

//can only choose left diagonal or right diagonal   -- WRONG INTERPRETATION


//can choose all except the previously choosen one's vertical neighbour


//variable starting point, variable ending point
// going from bottom to top

