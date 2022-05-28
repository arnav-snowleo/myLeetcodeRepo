// BIT MANIPULATION

// [3,0,1] ->missing is 2    

// [0,1,3] -> given array
// [1,2,3] -> xorwith      (start from 1 to size inclusive)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int res = 0;
        for(int i=0;i<nums.size();i++){
            
            res ^= nums[i];
            res ^= (i+1);
        }        
        return res;        
    }
};