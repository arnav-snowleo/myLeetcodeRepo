// sorted array , solution must run in O(log n) -- hints binary search


// BRUTE APPROACH : bit manipulation , O(n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int x = 0;
        for(int i=0;i<n;i++){
            x ^= nums[i];
        }
        return x;
    }
};