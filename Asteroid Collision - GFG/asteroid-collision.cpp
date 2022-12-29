//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &nums) {
        stack<int> s;
        
        for(int i=0; i<n; i++) {
            if (nums[i] > 0) s.push(nums[i]);
            else {
                while(s.size() && s.top()>0 && s.top() < abs(nums[i]))
                s.pop();
                
                if(!s.size() || s.top()<0) 
                s.push(nums[i]);
                
                if(s.top() + nums[i] == 0)
                s.pop();
            }
        }
        
        vector<int> ans(s.size());
        int i = s.size()-1;
        while(s.size()) {
            ans[i--] = s.top();
            s.pop();
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends