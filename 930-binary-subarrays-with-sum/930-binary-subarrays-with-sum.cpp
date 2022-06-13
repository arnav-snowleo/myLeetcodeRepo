//   SLIDING WINDOW
//   helper(nums,goal) - helper(nums,goal-1);  
//   count += j-i+1; 

class Solution {
private:
    int helper(vector<int>& nums, int goal){
        int i=0,j=0,n= nums.size(),sum=0,count=0;        
        
        if(goal<0) return 0;
        
        while(j<n){
            
            sum+= nums[j];            
            
            while(sum > goal){   //BREAKING CONDITION INSIDE THIS WHILE LOOP
     
                sum -= nums[i];  //remove
                i++;             //slide left ptr
            }
           
            count += j-i+1;      //size of window
            cout<<count<<" ";
            
            j++;                        
        }        
        return count;  
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return helper(nums,goal) - helper(nums, goal-1) ;   //WHY?? //need clarity here 
    }
};