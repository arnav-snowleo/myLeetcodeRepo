class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int size = candies.size() , maxi = INT_MIN;
        for(int i=0;i<size;i++)
            maxi = max(maxi, candies[i]);

        vector<bool> res(size,true);
        for(int i=0;i<size;i++){
            if( candies[i]+extraCandies <maxi)
                res[i] = false;
        }
        return res;
    }
};