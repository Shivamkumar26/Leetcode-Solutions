//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
    int i = 0;
    while (i < n) {
        if (s[i] == '1') {
            int left = x, curr = i - 1;
            while (curr >= 0 && s[curr] == '0' && left > 0) {
                s[curr] = '-';
                curr--;
                left--;
            }
            int right = x, cur = i + 1;
            while (cur < n && s[cur] == '0' && right > 0) {
                s[cur] = '-';
                cur++;
                right--;
            }
            s[i] = '-';
        } 
        i++;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') {
            return false;
        }
    }
    return true;
}

};
/*

*/

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends