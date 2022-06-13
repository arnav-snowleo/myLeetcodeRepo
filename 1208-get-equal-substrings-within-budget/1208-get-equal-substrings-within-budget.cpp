class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length(), maxi =INT_MIN,i=0,j=0,cost=0;
        
        while(j<n){
            
            cost += abs(s[j]-t[j]);
            
            while(cost>maxCost){          //write breaking condition always
                
                cost -= abs(s[i]-t[i]);
                i++;
            }
            maxi = max(maxi , j-i+1);
            j++;           
        }       
        return maxi;
    }
};