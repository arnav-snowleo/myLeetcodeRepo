// SPACE OPTIMIZED: WITHOUT USING EXTRA SPACE  
// TC: 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

//         if(m==0 && n!=0)  nums1 = nums2;   
        
//         for(int i=0;i<n;i++){                 // O(n)
//             nums1[m+i] = nums2[i]; 
//         }
//         sort(nums1.begin() , nums1.end());    // O((n+m)logn) 
        
        int i=0,j=0;
        while(i<m && j<n){                           //O(m+n)  
            
            if(nums1[i] <= nums2[j]){
                i++;
            }else{
                swap( nums1[i] , nums2[j]);
                sort(nums2.begin() , nums2.end());   //O(nlogn)
            }
        }
        
        for(int i=0;i<n;i++){                        //O(n)
            nums1[m+i] = nums2[i];
        }
        
        
        //worse TC:
        //O(n) + O((m+n) * nlogn )
    }
};
 
