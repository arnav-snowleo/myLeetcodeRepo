class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> factorList;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                factorList.emplace_back(i);
                if(i!= (n/i))factorList.emplace_back(n/i);
            }
        }
        sort(factorList.begin(), factorList.end());
        if(factorList.size()<k)
            return -1;
        return factorList[k-1];
    }
};
//Brute