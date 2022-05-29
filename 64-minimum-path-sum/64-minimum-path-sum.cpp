class Solution {
private:
    int helper(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        //write base cases
        if(i<0 || j<0) return 10000;
        if(i==0 && j==0) return grid[0][0];       
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = helper(i-1,j , grid, dp) + grid[i][j];
        int left = helper(i,j-1 , grid, dp) + grid[i][j];
        
        return dp[i][j] = min(up , left);
        
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();        
        vector<vector<int>> dp(m , vector<int>(n,-1));
        
        return helper(m-1,n-1,grid,dp);        
    }
};