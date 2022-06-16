// sorted array , solution must run in O(log n) -- hints binary search
// OPTIMIZED APPROACH - binary search - O(logn)


// recursive approach 

class Solution {
private:
    int helper(vector<int>& nums, int start, int end){
        
        if(start>end) return -1;
        
        if(start==end){
            return nums[end];
        }                 
            
        int mid = start + (end-start)/2;
        int ans = nums[mid];
            
        if(nums[mid]==nums[mid+1]){
            ans = max(helper(nums, start, mid-1),helper(nums, mid+2, end));    
        }
        else if(nums[mid]==nums[mid-1]){
            ans = max(helper(nums, start, mid-2),helper(nums, mid+1, end));       
        }        
        
        return ans;
    }
    
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        return helper(nums,0,n-1);
    }
};







/*
// BRUTE APPROACH : bit manipulation , O(n)

        int n = nums.size();
        int x = 0;
        for(int i=0;i<n;i++){
            x ^= nums[i];
        }
        return x;

*/