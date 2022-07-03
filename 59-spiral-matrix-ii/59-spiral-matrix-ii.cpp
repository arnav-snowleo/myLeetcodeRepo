class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n,0));
        int minrow=0,mincol=0,maxrow=n-1,maxcol=n-1,count=1,total=n*n;
        
        while(count<=total && minrow<=maxrow && mincol <=maxcol){
            
            //TOP
            for(int i=mincol;i<=maxcol && count<=total;i++){
                ans[minrow][i] = count;
                count++;
            }
            minrow++;
            
            //RIGHT
            for(int i=minrow;i<=maxrow && count<=total;i++){
                ans[i][maxcol] = count;
                count++;
            }
            maxcol--;            
            
            //BOTTOM
            for(int i=maxcol;i>=mincol && count<=total;i--){
                ans[maxrow][i] = count;
                count++;
            }
            maxrow--;
            
            //LEFT
            for(int i=maxrow;i>=minrow && count<=total;i--){
                ans[i][mincol] = count;
                count++;
            }            
            mincol++;
        }       
        return ans;        
    }
};