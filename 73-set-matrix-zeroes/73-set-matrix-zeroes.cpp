class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();     //rows
        int n = matrix[0].size();  //colms

        // int flag = INT_MAX + 2;
        int flag = 2147483649;
        
        for(int i=0;i<m;i++){           
            
            for(int j=0;j<n;j++){                
                
                if(matrix[i][j] ==0){
                    
                    //traverse the corresponding row and put FLAG if ALREADY NOT ZERO
                    for(int k = 0;k<m;k++){
                        
                        if(matrix[k][j] != 0)
                            matrix[k][j] = flag;
                        
                    }
                    //traverse the corresponding colm and put FLAG if ALREADY NOT ZERO
                    for(int l = 0;l<n;l++){
                        
                        if(matrix[i][l] != 0)
                            matrix[i][l] = flag;
                         
                    }                  
                }               
            }
        }
        
        
        for(int i=0;i<m;i++){           
            
            for(int j=0;j<n;j++){                
                
                if(matrix[i][j] == flag){                    
                    matrix[i][j] = 0 ;               
                }               
            }
        }

       
    }
};