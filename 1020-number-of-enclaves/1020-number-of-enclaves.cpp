// TYPE: START DFS FROM BOUNDARY NODES

// we cannot walk off, if and only if any land is connected to < land at boundary >

// 0 - water
// 1 - land

class Solution {
private:
    void dfs(int i,int j, int row, int col, vector<vector<int>>& grid){
        
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] != 1) return;
        
        grid[i][j] = 2;
        
        dfs(i+1,j, row, col, grid);
        dfs(i-1,j, row, col, grid);
        dfs(i,j+1, row, col, grid);
        dfs(i,j-1, row, col, grid);      
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j] == 1) 
                    dfs(i,j,m,n, grid);
            }
        }       
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 1) count++;
            }
        }
        return count;       
    }
};