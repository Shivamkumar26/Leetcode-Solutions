//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int n) {
      
      sort(arr.begin(), arr.end());
      long long ans = 0;
      int cc = arr[0]+1;
      for(int i=1; i<n; i++) {
          if(cc >= arr[i]) { 
              ans += cc-arr[i];
              cc++;
          }
          else cc = arr[i]+1;
      }
        return ans;
    }
};
/** 

 arr - 5 6 7 5 5 4 6 6 3 3 
      
 sor - 3 3 4 5 5 5 6 6 6 7
 
       0 1 1 1 2 3 3 4 5 5 
       
 
 25
 
 mx = 5
                 13
 3 3 3 4 9 10 10 11 12 
 
 0 1 2 2 0 0  1  1  1 
 
 ans - 3 
 
 
 

**/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends