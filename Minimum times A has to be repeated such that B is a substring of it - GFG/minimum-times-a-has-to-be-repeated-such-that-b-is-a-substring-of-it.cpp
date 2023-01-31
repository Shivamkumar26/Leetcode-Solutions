//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        string temp = a;
        int ans = 1;
        int n = a.length();
        int m = b.length();
        
        while (temp.length() < m) {
            temp += a;
            ans++;
        }
        if(temp.find(b)!=string::npos) return ans;
        temp+=a;
        ans++;
        if(temp.find(b)!=string::npos) return ans;
        return -1;
    }
};

/**

abcd

acbd

qwq
qwqwqwqwqwqwqwqw


C

------------------

sql 
dbms
oops - access modifiers

**/


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends