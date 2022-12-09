//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    // write code here
    long long ans = 0;
    int mod = 1000000007;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int sub = 0;
            if(i-2>=0 && j-1>=0) sub++;
            if(i+1<n && j-2>=0) sub++;
            if(i+2<n && j+1<m) sub++;
            if(i-1>=0 && j+2<m) sub++;
            
            if(i+2<n && j-1>=0) sub++;
            if(i-2>=0 && j+1<m) sub++;
            if(i-1>=0 && j-2>=0) sub++;
            if(i+1<n && j+2<m) sub++;
            
            ans = (ans%mod + (n*m -(sub+1))%mod)%mod;
        }
    }
    return ans;
}

/** 

no. of cells apart from curr - 4 dir target points 

**/