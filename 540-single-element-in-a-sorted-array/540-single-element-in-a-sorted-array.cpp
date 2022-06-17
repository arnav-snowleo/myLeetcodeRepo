// sorted array , solution must run in O(log n) -- hints binary search
// OPTIMIZED APPROACH - binary search - O(logn)

// most optimized approach - binary search - odd even index approach

class Solution {    
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size(),start=0,end=n-1;
        
        while(start<end){
            
            int mid = start + (end-start)/2;
            
            if(mid%2 == 0){                         //mid at even index
                if(nums[mid] != nums[mid+1]) end = mid;                   // ele is in left part
                else start = mid+1;                                       // ele is in right part
            }
            else{                                   //mid at odd index
                if(nums[mid] != nums[mid+1]) start = mid+1;               // ele is in right part
                else end = mid;                                           // ele is in left part
            }           
        }       
        return nums[start];
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


/*
RECURSIVE APPROACH: modifying the binary seacrh
// private:
//     int helper(vector<int>& nums, int start, int end){
        
//         if(start>end) return -1;
        
//         if(start==end){
//             return nums[end];
//         }                 
            
        
//         int ans = nums[mid];
            
//         if(nums[mid]==nums[mid+1]){
//             ans = max(helper(nums, start, mid-1),helper(nums, mid+2, end));    
//         }
//         else if(nums[mid]==nums[mid-1]){
//             ans = max(helper(nums, start, mid-2),helper(nums, mid+1, end));       
//         }        
        
//         return ans;
//     }
*/