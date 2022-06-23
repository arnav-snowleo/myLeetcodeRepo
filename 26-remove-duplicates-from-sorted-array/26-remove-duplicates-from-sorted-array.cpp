// OPTIMISED:

// USING TWO POINTERS

// if lptr == rptr, increment rptr
// if different, increment lptr, update val at lptr 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size(),i=0;

        for(int j=0;j<n;j++){
            
            if(nums[i]==nums[j]){
                // j++;
            }else{
                i++;
                nums[i] = nums[j];
            }                   
        }        
        return i+1;        
    }
};






// // BRUTE: 

// // USING A SET

// //set stores unique ele, only
// //clear array
// //then put set elements into the array

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {

//         int n = nums.size();
        
//         set<int> s;
//         for(int i=0;i<n;i++){
            
//             s.insert(nums[i]);        
//         }        

//         nums.clear();
        
//         for(auto it: s){
//            nums.emplace_back(it);
//         }
        
//         return s.size();        
//     }
// };