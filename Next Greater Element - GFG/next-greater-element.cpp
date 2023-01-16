//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<long long> s;      
        vector<long long> ans;
        
        for(int i = n-1; i>=0; i--) {
            while(s.size() && s.top() <= arr[i]) s.pop();
            
            if(s.size()) ans.push_back(s.top());
            else ans.push_back(-1);
            
            s.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* 
6 8 0 1 3
8 -1 1 3 -1


8

*/



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends