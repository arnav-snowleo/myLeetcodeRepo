class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size(), j=0, count=0, maxi = INT_MIN;
        
        for(int i=0;i<n;i++){            
            
            //counter or hashmap
            if(nums[i]==0) count++;
            
            //while loop to slide window
            while(count>k && j<n){
                
                if(nums[j]==0)
                    count--;
                j++;
            }
            
            //operation according to problem statement
            maxi = max(maxi, i-j+1);
        }
        
        return maxi;
        
    }
};