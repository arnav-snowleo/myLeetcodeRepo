class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>set1 (nums1.begin() , nums1.end());
        unordered_set<int>set2 (nums2.begin() , nums2.end());

        for(auto it: nums2) if(set1.find(it) != set1.end()) set1.erase(it);
        for(auto it: nums1) if(set2.find(it) != set2.end()) set2.erase(it);

        return {vector<int>(set1.begin() , set1.end()) , vector<int>(set2.begin() , set2.end())};
    }
};