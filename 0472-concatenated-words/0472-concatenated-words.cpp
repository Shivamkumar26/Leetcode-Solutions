class Solution {
    bool isConcatenated(int i, int count, string &s, unordered_set<string> &allWords, vector<vector<int>> &dp){
        int n = s.size();
        if(i >= n) {
            if(count >= 2) return true;
            else return false;
        }
        if(dp[i][count] != -1) return dp[i][count];

        bool ans = false;
        for(int j=i;j<n;j++){
            string subStr = s.substr(i, j-i+1);
            if(allWords.find(subStr) != allWords.end()) {
                ans = ans or isConcatenated(j+1, count+1, s, allWords, dp);
            }
        }

        return dp[i][count] = ans;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> allWords;
        for(auto s: words){
            allWords.insert(s);
        }

        vector<string> ans;
        for(auto s: words){
            vector<vector<int>> dp(31, vector<int> (31, -1));
            if(isConcatenated(0, 0, s, allWords, dp)) 
                ans.push_back(s);
        }
        return ans;     //(On^n * N) + O(n + N)
    }
};