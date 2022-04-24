class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
                
        //FIND ALL SUBSETS USING RECURSION OR USING POWER SET  
        
        int subsetXorSum=0;
        int y = nums.size();
        int x = (int)pow(2,y);        
        
        for(int num=0; num<x; num++){            
            
            int xorSum = 0;
            for(int i=0; i<y; i++){
                
                if(num & (1<<i)){                    
                    xorSum ^= nums[i];                   
                }
            }
            subsetXorSum += xorSum;         
        }
        return subsetXorSum;
        
    }
};