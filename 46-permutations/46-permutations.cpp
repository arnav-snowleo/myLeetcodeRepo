class Solution {
private:
    void recursivePermute(int index , int size, vector<int> &nums, vector<vector<int>> &ans){
        
        // Recursive solution
        // SWAPPING 
        // extra space for ds, freq[] not used
        
        if(index == size){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<size;i++){
            swap(nums[index], nums[i]);                   // swap
            recursivePermute(index+1 , size, nums, ans);  // recur
            swap(nums[index], nums[i]);                   // re-swap on way back
        }        
             
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        recursivePermute(0,n,nums,ans);
        return ans;
        
    }
};