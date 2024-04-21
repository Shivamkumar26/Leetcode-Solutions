class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp; 
        int n = word.size(), ans = 0;

        for(int i=0; i<n; i++) {
            if(word[i]>='a' && word[i]<='z') {
                mp[word[i]]=i;
            }
            else if(word[i]>='A' && word[i]<='Z' && mp.find(word[i])==mp.end()) {
                mp[word[i]]=i;
            }
        }

        for(int i=0; i<n; i++) {
            if(word[i]>='A' && word[i]<='Z') {
                int diff = word[i] - 'A';
                char ch = 'a' + diff;
                if(mp.find(ch)!=mp.end() && mp[ch] < mp[word[i]]) {
                    ans++;
                    mp[ch] = INT_MAX;
                }
            }
        }
        return ans;
    }
};