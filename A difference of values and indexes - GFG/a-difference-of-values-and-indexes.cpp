//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int nums[], int n) 
    { 
        // Complete the function
        int ans = INT_MIN;
        int mx1 = INT_MIN;
        int mn1 = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            mx1 = max(mx1, nums[i]-i);
            mn1 = min(mn1, nums[i]+i);

            int v1 = nums[i]+i - mn1;
            int v2 = mx1 - nums[i]+i;
            
            ans = max({ans, v1, v2});
        }
        
        return ans;
    } 
};

/**

-(a[i] + i) + (a[j] + j)
(a[i] - i) - (a[j] - j)

**/

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends