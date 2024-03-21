class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = s.size();
        long long count = 0, c2=0;
        for(int i=0; i<n; i++) {
            if(s[i]==c) c2++;
        }
        count = (long long)c2*(c2+1)/2;
        return count;
    }
};