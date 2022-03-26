class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        bool isAp = true;
        
        int d = arr[0] - arr [1];
        for(int i = 0;i<arr.size()-1;i++){           
                
            if(arr[i] - arr [i+1] ==d){
                //continue
            }else{
                isAp = false;
                break;
            }
        }
        
        return isAp;
        
    }
};