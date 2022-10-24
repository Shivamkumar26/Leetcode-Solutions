class Solution {
    int solve(vector<string>& arr, int ind, string str) {
        unordered_set<char> s(str.begin(), str.end());
        if(s.size()!=str.size()) return 0;
        
        int res = str.size();
        for(int i=ind; i<arr.size(); i++)
            res = max(res, solve(arr, i+1, str+arr[i]));
        return res;
    }
public:
    int maxLength(vector<string>& arr) {
        return solve(arr, 0, "");
    }
};