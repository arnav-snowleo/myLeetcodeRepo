//1 - land
//0-  water
//2- already visited land

// whenever i cannot go from particular land cell, increment the counter
// maybe because for boundary hinderance, or water hinderance
// do nothing if already visited  

// but ,if I am at grid[1][1] ->can go everywhere, so don't increase counter at all

class Solution {
public:
    int count =0;
    void dfs(int i, int j, int row, int col, vector<vector<int>>& grid){
        
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] == 0 ) {
            count++;
            return;
        }
        if(grid[i][j] == 2) return;
        
        grid[i][j] = 2;
        
        dfs(i+1,j,row, col, grid);
        dfs(i-1,j,row, col, grid);
        dfs(i,j+1,row, col, grid);
        dfs(i,j-1,row, col, grid);
           
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans =0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1) {
                    dfs(i,j,m,n,grid);
                    break;
                }
            }
        }
        
        return count;       
    }
};