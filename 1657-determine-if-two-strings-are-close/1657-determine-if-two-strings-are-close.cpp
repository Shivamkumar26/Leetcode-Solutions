class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<int> f1(26,0), f2(26,0);
        set<char> s1; set<char> s2;

        for(int i=0; i<n; i++) {
            f1[word1[i]-'a']++;
            s1.insert(word1[i]);
        }for(int i=0; i<m; i++) {
            f2[word2[i]-'a']++;
            s2.insert(word2[i]);
        }
                
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1==f2 && s1==s2;
    }
};