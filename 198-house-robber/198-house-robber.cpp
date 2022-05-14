// MAXIMUM SUM OF NON-ADJACENT ELEMENTS

// TRY OUT ALL POSSIBLE WAYS -- recursion
// overlapping subproblems found -- (DP problem) - can memoize
//                                               - tabulation -> (index-1 , index-2) present --space optimize

class Solution {
public:
    int rob(vector<int>& nums) {
        
        // TABULATION APPROACH - bottom up - space optimized -- O(1) space
       
        int n = nums.size();
        int prev = nums[0];     
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            
            int pick = nums[i] ;            
            if(i>1) pick += prev2;
            int not_pick = 0 + prev;
            
            int curr = max(pick, not_pick);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;        
    }
};