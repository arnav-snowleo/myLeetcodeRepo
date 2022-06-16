// USING STL, merge()  // O(nlogn) is TC of merge sort

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans = 0.00;
        
        int len = nums1.size() + nums2.size();
        vector<int> nums3(len);
        
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin() );
        
        if(len %2 != 0){            
            double x = (len + 1)/2.00;
            return nums3[x-1];
        }else{
            
            double x = len/2;
            return (nums3[x-1] + nums3[x]) / 2.00;            
        }        
        return ans;       
    }
};