class Solution {
private:
    void dfs(int i, int j, int newColor, int row, int col,vector<vector<int>>& grid){
        
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] != oldColor) return;
        
        grid[i][j] = newColor;
        
        dfs(i-1,j,newColor,row,col,grid);
        dfs(i+1,j,newColor,row,col,grid);
        dfs(i,j-1,newColor,row,col,grid);
        dfs(i,j+1,newColor,row,col,grid);
        
    }
public:
    int oldColor = 0;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(newColor==image[sr][sc]) return image;  //missed this
        
        int m = image.size();
        int n = image[0].size();
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==sr && j==sc) {
                    oldColor = image[i][j];
                    dfs(sr,sc,newColor, m,n, image);
                }
            }
        }
        return image;
    }
};