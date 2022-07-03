class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        int minrow =0, mincol =0, maxrow = m-1, maxcol = n-1,count=0,total=m*n;
        
        vector<int> ans;
        
        while(minrow<= maxrow && mincol<= maxcol && count<total){
            
            //TOP
            for(int i=mincol;i<=maxcol && count <total ;i++){
                ans.push_back(matrix[minrow][i]);
                count++;
            }
            minrow++;
            
            //RIGHT
            for(int i=minrow;i<=maxrow && count <total ;i++){
                ans.push_back(matrix[i][maxcol]);
                count++;
            }
            maxcol--;
            
            //BOTTOM
            for(int i=maxcol;i>=mincol && count<total ;i--){
                ans.push_back(matrix[maxrow][i]);
                count++;
            }
            maxrow--;
            
            //LEFT
            for(int i=maxrow;i>=minrow && count<total;i--){
                ans.push_back(matrix[i][mincol]);
                count++;
            }
            mincol++;           
        }       
        return ans;        
    }
};