class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //no negative elements
        //sorting
        //TC: O(nlogn)
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
        
    }
};

// TEKION, don't sort, negative elements present