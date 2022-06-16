// using 3 pointers //sorting // without using set  JUST SKIP  DUPLICATES
// i pointer, sort and use left pointer, right pointer

// no duplicate triplets. // skip the repeating elements
// USEd SET for removing duplicates: O(logn) time for insertion
    
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();        
        sort(nums.begin(), nums.end());        
        vector<vector<int>> ans;
        if(n < 3)  return ans;
        
        for(int i=0;i<n-2;i++){   
            
            //TO SKIP DUPLICATES, this if statement
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                
                int j = i+1,k=n-1;
                int rem_sum = -nums[i];
                while(j<k){
                    if(nums[j] + nums[k] == rem_sum ){       
                        ans.push_back({nums[i], nums[j], nums[k]});
                                                
                        //THESE TWO WHILE LOOPS ENUSRE DUPLICATES ARE SKIPPED
                        while(j<k && nums[j]==nums[j+1]){j++;}
                        while(j<k && nums[k]==nums[k-1]){k--;}
                        
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
        }
        
        return ans;
    }
};