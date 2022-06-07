class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        
        int m = flowerbed.size();
        if(m==1 && flowerbed[0] != n) return true;

        for(int i=0;i<m;i++){
            
            bool left = (i-1>=0) ? ( flowerbed[i-1]==0 ? true : false ) : true ;
            bool right = (i+1 < m) ? ( flowerbed[i+1]==0 ? true : false ) : true ;
            
            if(flowerbed[i] == 0 && left && right) {
                flowerbed[i] = 1;
                n--;
                if(n==0) return true;                
            }            
        }         
        
        return n<=0;
    }
};