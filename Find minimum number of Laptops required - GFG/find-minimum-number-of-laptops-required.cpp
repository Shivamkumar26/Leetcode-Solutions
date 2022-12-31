//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


/*

1 2 5
2 3 6

*/

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        sort(start, start+n);
        sort(end, end+n);
        
        int curr = 1, prev = 0, ans = 1;
        while(curr < n && prev < n) {
            if(start[curr] < end[prev]) {
                ans++;
                curr++; 
            }
            else {
                prev++;
                curr++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends