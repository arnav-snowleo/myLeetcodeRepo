class Solution {
public:
    int kthFactor(int n, int k) {

        set<int> factorList;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                factorList.insert(i);
                factorList.insert(n/i);
            }
        }
        
        vector<int> factors;
        for(auto it: factorList)
            factors.emplace_back(it);
        
        if(factors.size()<k)
            return -1;
        return factors[k-1];

    }
};
// Little optimised -> TC: O(sqrt(n)) SC: O(numberOfFactors), 
// using set, set stores in ascending order