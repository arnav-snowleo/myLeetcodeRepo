// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
private: 
    void recursiveSubsetSum(int index, int size, vector<int> &arr, vector<int> &ans, int sum){
        
        if(index == size){
            // sum is subset sum
            ans.push_back(sum);
            return;
        }
        
        //PICK
        recursiveSubsetSum(index+1,size,arr,ans,sum+arr[index]);
        
        //NOT PICK
        recursiveSubsetSum(index+1,size,arr,ans,sum);
        
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum =0;
        recursiveSubsetSum(0,N,arr,ans,sum);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends