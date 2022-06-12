//  SLIDING WINDOW
//  HASHMAPS

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int i=0,j=0,types=0,sum=0, maxi = INT_MIN, n = fruits.size();

        unordered_map<int,int> mp;
        
        while(j<n){
            
            mp[fruits[j]]++;
            
            while(mp.size()>2){
                //left pointer
                mp[fruits[i]]--;                           //decrement
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);  //if 0 remove
                i++;                                       //slide left ptr
            }
            
            maxi= max(maxi, j-i+1); //max size of window is what we need                
            j++; 
        }
        return maxi == INT_MIN ? 0 : maxi;       
    }
};