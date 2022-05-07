class Solution {
private:
    void allsubsets(int index , int size,vector<int>& nums, vector<int>& ds , vector<vector<int>>& ans){
        
        //RECURSIVE Method         
        //either take an or not take 
        
        // TAKE       
        
        // put in data_str
        // recur fnxn call
        // come back remove from data_str         
        
        
        // NOT TAKE
        
        //recur fnxn call 
       
        if(index == size){
            ans.push_back(ds);
            return;                               //was missing this "return", so address sanitizer
        }     
        
        ds.push_back(nums[index]);                        // take
        allsubsets(index+1, size,nums , ds , ans);        // call recursive fnxn
        ds.pop_back();                                    // remove ele while coming back
                         
        allsubsets(index+1, size,nums, ds , ans);         // not take and call recur fnxn               
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();       
        vector<int> ds;        
        vector<vector<int>> ans;
        
        allsubsets(0, n, nums, ds , ans);
        
        return ans;
    }
};