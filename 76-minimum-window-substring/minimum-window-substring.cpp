class Solution {
public:
    string minWindow(string s, string t) {
       int n = s.size(), m = t.size();
       string ans = "";

       if(m > n) return ans;
       unordered_map<char, int> mp;
       for(int i=0; i<m; i++) mp[t[i]]++;

       int count = mp.size(), l = 0;
       for(int i=0; i<n; i++) {
        mp[s[i]]--;
        if(mp[s[i]] == 0) {
            count --;
            if(count == 0) {
                //trim from left
                while(mp[s[l]] < 0) {
                    mp[s[l]]++;
                    l++;
                }
                string temp = s.substr(l, i-l+1);
                if(ans == "") ans = temp;
                if(temp.size() < ans.size()) ans = temp;
                mp[s[l]]++;
                l++;
                count++;
            }
        }
       }
       return ans;
    }
};
/*
"ADOBECODEBANC"
"ABC"

count = 0

a:0
b:0
c:0

d:-1
o:-1
e:-1



*/