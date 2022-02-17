class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        //  When something is important enough, 
        //  you do it even if the odds are not in your favor.
        
        
        vector<vector<int>> res(r, vector<int>(c));
        
        int m = mat.size();     // num of rows
        int n = mat[0].size();  // num of columns
         
        // checking possibilty    
        if(r*c == m*n){
            //reshape matrix
            
            int row = 0;
            int col = 0;
            for(int i=0;i<m;i++){
                
                for(int j=0;j<n;j++){
                    
                    res[row][col] = mat[i][j];
                    
                    col++;
                    if(col == c){
                        row++;
                        col = 0;
                    }
                    
                }
            }
            
            return res;
        
        }
        else{
            return mat;
        }
        
    }
};