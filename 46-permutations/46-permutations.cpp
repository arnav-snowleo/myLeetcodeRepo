class Solution {
private:
    
    void allPermutations(int size, vector<int> &ds,int freq[] , vector<int> &nums, vector<vector<int>> &ans ){        
        
        // Base case        
        if(ds.size() == size){
            ans.push_back(ds);
            return;
        }
        
        for(int i =0;i<size;i++){
            
            if(!freq[i]){                               // can pick and add if freq != 1
                
                ds.push_back(nums[i]);                          // pick
                freq[i] = 1;                                    // mark
                allPermutations(size, ds, freq, nums, ans);
                
                // go up
                
                freq[i] = 0;                                    // unmark
                ds.pop_back();                                  // remove              
                
            }
        } 
        
    }    
    
public:
    vector<vector<int>> permute(vector<int>& nums) {   
        
        // USING RECURSION 
        // approach 1- uses extra space for <ds, freq array> 
        // freq array is used to flag indices, with 0 or 1
        
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();        
        
        int freq[n];        
        for(int i=0;i<n;i++) freq[i] = 0;
        
        allPermutations(n,ds,freq ,nums,ans);      

        return ans;
    }
};