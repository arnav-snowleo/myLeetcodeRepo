class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // without using inbuilt function
        
        // four steps
        
        // STEP 1 .
        //  from back iterate and stop at breaking point ( where order broke )
                     // order not broken thoughout is possible
                     // just reverse the i/p in that case
        // O(n)
        
        // STEP 2. 
        // find smallest greater element to the element at breaking point index
        // O(n)
        
        // STEP 3.
        // swap both
        
        // STEP 4.
        // reverse from back till the breaking point index
        // O(n)
        
        int n = nums.size() , k ,l;
        
        for(k=n-2;k>=0;k--){
            
            if(nums[k] < nums[k+1]){
               break;              
            }
            
        }       
        if(k<0){  // iterated once, no breaking point found            
            reverse(nums.begin() , nums.end());
        }
        
        else{
        //STEP 2. find the next(closest) greatest element to that of element at index k
        for(l=n-1;l>k;l--){
            if(nums[l] > nums[k]){
                //we got l also
                break;
            }
        }
        
        //STEP 3.
        swap(nums[k] , nums[l]);
        
        //STEP 4.
        // reverse from k+1 to last
        reverse(nums.begin()+k+1  , nums.end());

        }  
        
        
        // using inbuilt function
        // next_permutation(nums.begin() , nums.end());
        
    }
};