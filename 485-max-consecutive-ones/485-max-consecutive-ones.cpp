// SUM UP, if 1  , update maxi
// set sum to zero, if 0

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxi = 0,sum=0,n = nums.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==1) {
                sum+=1;
                maxi = max(maxi,sum);
            }else{
                sum=0;
            }
        }
        return maxi;
    }
};