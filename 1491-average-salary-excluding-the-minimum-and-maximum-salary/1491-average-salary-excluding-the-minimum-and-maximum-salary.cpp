class Solution {
public:
    double average(vector<int>& salary) {
        
        sort(salary.begin() , salary.end());        
        
        int count  = 0;
        int sum = 0;
        
        for(int i = 0;i< salary.size()-1 ; i++){
            
            sum += salary[i];
            count++;            
            
        }
        
        sum -= salary[0];
        int m = count -1;
        double average = sum / (1.0 * m);
        return average;
        
        
        
    }
};