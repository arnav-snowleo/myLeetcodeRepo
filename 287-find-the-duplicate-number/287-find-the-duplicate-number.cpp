class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          
        // other solution using maps is working fine, but is of high T(0)
        
        set<int> st;
        
        for (auto it: nums){
            
            if(st.count(it))
                return it;
            st.insert(it);
        }
        
        return -1;
        
        // space -> O(n)
        
        // solution using set sum method is wrong for test case [2,2,2,2,2] as elements can be repeated
        
//         int sum = 0;
        
//         for(int i=0;i<nums.size();i++){
//             sum += nums[i];
//         }
        
        
//         set<int> st;
//         int setSum  = 0;
//         for(int i=0;i<nums.size();i++){
//             st.insert(nums[i]);
//         }
        
//         for(auto it: st){
//             setSum += it;
//         }
        
//         return sum - setSum;

    }
};