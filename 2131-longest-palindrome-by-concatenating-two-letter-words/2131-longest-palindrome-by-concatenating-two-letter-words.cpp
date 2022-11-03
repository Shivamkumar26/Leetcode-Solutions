class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp2; // samefreq
        
        int count = 0;
        for(int i=0; i<words.size(); i++) {
            if(words[i][0]==words[i][1]) // both ele same
                mp2[words[i]]++;
            
            else {
            if(mp.find(words[i])==mp.end() || mp[words[i]]<=0) {
                swap(words[i][0], words[i][1]);
                mp[words[i]]++;
            }
            else {
                count+=4;
                mp[words[i]]--;
            }
            }
        }
        int one = 0;
        for(auto i = mp2.begin(); i != mp2.end(); i++) {
            if(i->second % 2 == 1) one = 2;
            count += (i->second/2) * 4;
        }
        return count + one;
    }
};