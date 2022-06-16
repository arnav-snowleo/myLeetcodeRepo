// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start=0;
        int end=n;
        
        int ans = 0;
        while(start<=end){
            
            int mid = start+ (end-start)/2;   // THIS ensures integer overflow does not occur for ~~INT_MAX~~
            
            if(isBadVersion(mid)){    //true search left half                
                ans = mid;                
                end = mid-1;
            }else{               
                start = mid+1;        //false, search right half
            }
        }        
        return ans;
    }
};

// solve using binary search