class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int answer = 1;
        int negativeCount  = 0;        
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0){
                answer = 0;
                break;
            }
            if(nums[i] < 0){
                negativeCount++;
            }
        }
        
        if(negativeCount%2 != 0){
           answer = -1;
        }
        
        return answer;        
    }
};