//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();
        int mid = n/2;
        mid--;
        
        int len = 0;
        while(mid>=1) {
            string str1 = s.substr(0, mid+1);
            string str2 = s.substr(mid+1, mid+1);
            //cout << str1 << " -- " << str2 << endl;
            if(str1==str2) {
                len = str1.length();
                break;
            }
            mid--;
        }
        return len == 0 ? s.size() : s.size() - (len) + 1;
    }
};
/* 

abbbaa


abcabcabcabcaa


*/

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends