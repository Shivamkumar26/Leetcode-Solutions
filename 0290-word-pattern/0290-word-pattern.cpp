class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map <char, string> mp;
        unordered_map <string, char> mp2;
        
        int n = p.size(), m = s.size();
        int j=0;
        
        for(int i=0; i<n; i++) {
            string st = "";
            if(j>=m) return false;
            while(j<m && s[j]!=' ') st = st+s[j], j++;
            j++;
            if(mp.find(p[i]) == mp.end()){   
                mp[p[i]] = st;
            }
            else {
                if(st == mp[p[i]]) continue;
                return false;
            }
            
            if(mp2.find(st) == mp2.end()){   
                mp2[st] = p[i];
            }
            else {
                if(p[i] == mp2[st]) continue;
                return false;
            }
        }
        if(j<m) return false;
        return true;
    }
};