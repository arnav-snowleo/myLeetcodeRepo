// 0- land
// 1- water

// 1- mark visisted land as 1

//cannot be a closed island if 0 is at topmost row, bottommost row, rightmost col, leftmost col

class Solution {
private:
    bool isClosed(int x, int y,int row, int col,vector<vector<int>>& grid){
        
        if(grid[x][y] == 1) return true; //returning true, on hitting water, as we don't want to stop whole dfs
        if(x<=0 || y<= 0 || x>=row-1 || y>= col-1 ) return false;        
        
        grid[x][y] = 1;      
        
        bool right = isClosed(x+1, y, row, col, grid);   
        bool bottom = isClosed(x, y-1, row, col, grid);  
        bool left = isClosed(x-1, y, row, col, grid);   
        bool top = isClosed(x, y+1, row, col, grid);        
        
        return right && left && top && bottom;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();        
        
        int ans =0;
        for(int i=0;i <m;i++){
            
            for(int j=0;j<n;j++){
                
                //if land , check for island (closed island)                
                if(grid[i][j] == 0 && isClosed(i,j,m,n,grid)) ans++;               
            }
        }               
        return ans;
    }
};