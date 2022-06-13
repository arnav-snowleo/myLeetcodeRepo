// SLIDING WINDOW 
// maximum length of a substring - think of -- SLIDING WINDOW

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length(), maxi =INT_MIN,i=0,j=0,cost=0;
        
        while(j<n){
            
            // STEP 1
            cost += abs(s[j]-t[j]);
            
            // STEP 2
            while(cost>maxCost){          //write breaking condition always
                
                cost -= abs(s[i]-t[i]);   //remove 
                i++;                      //slide left ptr
            }
            
            //STEP 3
            maxi = max(maxi , j-i+1);
            j++;           
        }       
        return maxi;
    }
};