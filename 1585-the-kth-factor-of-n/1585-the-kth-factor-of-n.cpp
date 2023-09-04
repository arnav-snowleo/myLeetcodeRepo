class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> factorList;
        for(int i=1;i<=n;i++){
            if(n%i==0)
                factorList.emplace_back(i);
        }
        if(factorList.size()<k)
            return -1;
        return factorList[k-1];
    }
};
//Brute O(n)