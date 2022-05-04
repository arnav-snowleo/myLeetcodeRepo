class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        
        // find faulty elements
        // element is faulty if mountain is formed, 
        // take the element itself, prev, and next to check the mountain formation
        
        // if mountain found
        // update the "min" and "max" 
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int n = nums.size();
        if(n==1) return 0;
        
        for(int i=0;i<n;i++){
            
            //no previous element
            if(i==0){   
                
                //faulty if next is smaller
                
                if(nums[i+1]<nums[i]){
                    maxi = max(maxi , nums[i]);
                    mini = min(mini, nums[i]);                   
                }
                
            }
            //no last element
            else if(i==n-1){
                if(nums[i] < nums[i-1]){
                    maxi = max(maxi , nums[i]);
                    mini = min(mini, nums[i]);                    
                }
            }
            else{
                // if(prev is not less || next is not greater){
                if(nums[i-1] > nums[i] || nums[i+1] < nums[i]){
                    // nums[i] is faulty element
                    maxi = max(maxi , nums[i]);
                    mini = min(mini, nums[i]);                    
                }
            }
            
        }
        
        // if sorted array, "mini" and "maxi" will not get updated
        if(maxi == INT_MIN || mini == INT_MAX ) return 0;        

        // now find the correct position of "mini" and "maxi" element        
        int i,j;
        for(i=0;i<n && nums[i]<=mini;i++);
        
        for(j=n-1;j>=0&& nums[j]>=maxi ; j--);
        
        return j-i+1;
         
    }
};