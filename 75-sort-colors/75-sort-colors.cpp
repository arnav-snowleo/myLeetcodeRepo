class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // USING THREE POINTER METHOD
        //  --> DUTCH NATIONAL FLAG ALGORITHM
        
        // low,mid at start , high at end
        
        // [ 0 .. low-1] -> all are 0s        -- all ele to left of low ptr are 0s
        // [ high + 1 ... n] --> all are 2s   -- all ele to right of high ptr are 2s
        // [low and mid-1]   --> all are 1s   -- all ele in bw low and mid-1 are 1s
        
        // move mid ptr till it crosses high ptr
        // while moving 3 CHECKS
        // move ptr pts to
        //                      0 -> swap nums[mid] and nums[low]       ; low++ , mid++ 
        //                      1 ->                                    ;         mid++
        //                      2 -> swap nums[mid] and nums[high]      ; high--
        
        
        int n = nums.size();
        int low=0,mid=0,high=n-1;
         
        while(mid<=high){
            
            if(nums[mid] == 0){
                swap(nums[mid] , nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }   
        
        
        //COUNT AND SORT USING EXTRA VECTOR SPACE
        
//         vector<int> ans; 
//         map<int, int> mp;        
//         int n = nums.size(); 
        
//         for(int i=0;i<n;i++){            
//             mp[nums[i]]++;
//         }      
     
//         for(int j=0;j<mp.size();j++){
//             for(int i=0;i<mp[j];i++){
//                 ans.push_back(j);
//             }          
//         }        
//         nums= ans;        
    }
};