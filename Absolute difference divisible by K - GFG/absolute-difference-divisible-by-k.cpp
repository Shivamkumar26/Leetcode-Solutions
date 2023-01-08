//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        
        for(int i=0; i<n; i++) {
            ans+=(long long)mp[arr[i]%k];
            mp[arr[i]%k]++;
        }
        return ans;   
    }
};

/* 
1 3 6 10
arr = [1 2 3 4]
k = 2

a = 2

1, 2
0, 1


arr = [3, 7, 11, 15, 19]
k = 4

a = 3 + 3 + 4

0, 3





*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends