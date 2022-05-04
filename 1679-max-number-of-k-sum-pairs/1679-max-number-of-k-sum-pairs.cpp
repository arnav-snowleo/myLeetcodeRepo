class Solution {
public:
    int maxOperations(vector<int>& nums, int k) { 
        
        //Using Two pinters for O(n) solution
        
        sort(nums.begin() , nums.end());
        
        int i=0 , j= nums.size()-1;
        int count = 0;
        
        while(i<j){
            
            if(nums[i] + nums[j] == k){
                count++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
        
//        // Using map for O(n) solution
        
//        int count = 0; 
//        int n = nums.size();        
//        if(n ==1) return 0;
        
//        unordered_map<int,int> mp;
//        for(int i=0;i<n;i++){
           
//            if( mp[k-nums[i]] ){
//                count++;
               
//                mp[k-nums[i]]--; //remove
//                mp[nums[i]]--;   //remove
//            }
//            mp[nums[i]]++;
//        }
//        return count;
        
   
        // TLE for O(n*n)
//        int count = 0;        
//        int n = nums.size();
        
//        if(n ==1) return 0;
//        for(int i=0;i<n-1;i++){
           
//            for(int j=i+1;j<n;j++){
               
//                if((nums[i] + nums[j] == k ) && nums[i]!= -1 && nums[j] != -1){
//                    nums[i] = -1;
//                    nums[j] = -1;
//                    count++;
//                }
//            }
//        } 
//        return count;
        
    }
};