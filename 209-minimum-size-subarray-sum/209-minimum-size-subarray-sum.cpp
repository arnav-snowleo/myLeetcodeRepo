class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum =0, count=0,j=0,i=0, mini= INT_MAX, n= nums.size();
        while(j<n){
            
            sum+= nums[j];
            
            while(sum >= target){
                
                mini = min(mini, j-i+1);    // minimum sliding window size we need
                    
                //left pointer
                sum-= nums[i];
                i++;
            }
            j++;                                    
        }        
        
        return mini == INT_MAX ? 0 : mini;
    }
};