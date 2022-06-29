//using maps


class Solution {
public:
    int countTriples(int n) {
        
        int count =0;
        
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[i*i]++;
        }
        
        for(int i=1;i<=n;i++){        

            for(int j=i+1;j<=n;j++){
                
                if( mp.find( abs( (i-j)*(i+j) ) )  != mp.end()) count++;       
            }         
        }        
        return count;
    }    
};