// using 3 pointers //sorting //set
// i pointer, sort and use left pointer, right pointer

// no duplicate triplets. // USE SET O(logn) time for insertion
    
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();        
        sort(nums.begin(), nums.end());        
        vector<vector<int>> ans;
        set<vector<int>> setvector;
        if(n < 3)  return ans;
        
        for(int i=0;i<n-2;i++){           
        
            int j = i+1,k=n-1;
            int rem_sum = -nums[i];
            while(j<k){
                if(nums[j] + nums[k] == rem_sum ){       
                    setvector.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] < rem_sum){
                    j++;
                }else{
                    k--;
                }                
            }            
        }
        
        for(auto it: setvector){
            ans.push_back(it);
        }
        
        return ans;
    }
};