// USING FOUR POINTERS
// i,j   , left right

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int rem_sum = target - (nums[i]+ nums[j]);
                
                int left=j+1, right =n-1;
                
                while(left < right){
                    
                    int two_sum = nums[left] + nums[right];
                    
                    if(two_sum < rem_sum) left++;
                    else if(two_sum > rem_sum) right--;
                    else{
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        ans.push_back(quad);
                        
                        //JUMPING DUPLICATES for left and right ptr
                        while(left < right && quad[2] == nums[left]) ++left;
                        while(left < right && quad[3] == nums[right]) --right;
                    }                   
                } 
                
                //jumping duplicate for j
                while(j+1<n && nums[j+1] == nums[j]) ++j;
            }
            //jumping duplicate for i
            while(i+1<n && nums[i+1] == nums[i]) ++i;
        }
        
        return ans;
    }
};


// all possible quadruplets -- recursion
// might use backtracking
// checck if overlapping subproblems - use dp3