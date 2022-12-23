//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<int>& arr, int l, int r, vector<vector<int>>& dp) {
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        for(int i=l+1; i<r; i++) {
            int temp = arr[l]*arr[r]*arr[i] + solve(arr, l, i, dp)
            + solve(arr, i, r, dp);
            ans = max(temp, ans); //-ve elements
        }
        return dp[l][r] = ans;
    }
public:
    int maxCoins(int n, vector<int> &nums) {
        vector<int> arr(n+2);
        vector<vector<int>> dp(n+3, vector<int> (n+3, -1));
        n+=2;
        for(int i=0; i<n; i++) {
            if(i==0 || i==n-1) arr[i]=1;
            else arr[i] = nums[i-1];
        }
        
        return solve(arr, 0, n-1, dp);
    }
};

/**

3 1 5 8 

15

3 5 8


**/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends