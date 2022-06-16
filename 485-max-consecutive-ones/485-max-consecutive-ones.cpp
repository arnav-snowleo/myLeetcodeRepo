// SUM UP, if 1  , update maxi
// set sum to zero, if 0

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxi = INT_MIN,sum=0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==1) {
                sum+=1;
                maxi = max(maxi,sum);
            }else{
                sum=0;
            }
        }
        return maxi==INT_MIN? 0 :maxi;
    }
};