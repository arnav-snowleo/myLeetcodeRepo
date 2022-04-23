class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        //POWER SET METHOD
        
        //outer loop from o to 2power n -1
        
        //inner loop from 0 to size of vector
        
        //inner loop checks if bit is set in ith index, 
        //if bit is set in ith index, corresponding elemnt from vector is added to ans vector
        
        
        vector<vector<int>> ans;       
        int y = nums.size();
        int x = (int) pow(2,y) ;
        
        for(int i=0;i<x;i++){
            vector<int> arr;
            
            for(int j =0;j<y;j++){                
                
                //check if bit set
                // number from 0 to (2power n)-1 bitwise and & with (1<<j)
                if((i & (1<<j)) != 0){
                    arr.push_back(nums[j]);                    
                }                
            }            
            ans.push_back(arr);      
            
        }
        return ans;
    }
};