class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            if(mp.count(word)>1) {
                mp[word] = {strs[i]};
            }
            else {
                mp[word].push_back(strs[i]);
            }
        }
        vector<vector<string>> res;
        for(auto i=mp.begin(); i!=mp.end(); i++)
            res.push_back(i->second);
        return res;
    }
};