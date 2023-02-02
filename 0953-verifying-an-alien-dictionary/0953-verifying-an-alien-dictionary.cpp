class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        
        vector<string> w2 = words;
        
        for(int i = 0; i < w2.size(); i++) {
            string s = w2[i];
            for(int j = 0; j < s.size(); j++) {
                int ch = s[j], k = 0;
                while(ch != order[k]) k++;
                w2[i][j] = alpha[k];
            }
        }
        vector<string> words2 = w2;
        sort(words2.begin(), words2.end());
        return w2 == words2;
    }
};

/*

26

hlabcdefgijkmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz

ag

*/