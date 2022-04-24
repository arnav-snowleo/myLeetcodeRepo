class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int subsetXorSum=0;
        vector<int> xorArr;
        
        //FIND ALL SUBSETS USING RECURSION OR USING POWER SET  
        
        int y = nums.size();
        int x = (int)pow(2,y);
        
        for(int num=0; num<x; num++){            
            
            int xorSum = 0;
            for(int i=0; i<y; i++){
                
                if(num & (1<<i)){                    
                    xorSum ^= nums[i];                   
                }
            }
            xorArr.push_back(xorSum);           
        }
        
        for(auto it: xorArr){
            subsetXorSum += it;
        }
        
        return subsetXorSum;
        
    }
};