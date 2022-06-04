// SPACE OPTIMIZED: WITHOUT USING EXTRA SPACE
// TC: O((n+m)logn) + O(n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(m==0 && n!=0)  nums1 = nums2;   
        
        for(int i=0;i<n;i++){                 // O(n)
            nums1[m+i] = nums2[i]; 
        }
        sort(nums1.begin() , nums1.end());    // O((n+m)logn) 
    }
};
 
