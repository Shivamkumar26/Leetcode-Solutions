class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if(s.size()!=t.size()) return 0;

        // unordered_map<int, int> mp1, mp2;
        // for(int i=0; i<s.size(); i++) {
        //     if(mp1.find(s[i])!=mp1.end() && mp1[s[i]] != t[i]) return false;
        //     if(mp2.find(t[i])!=mp2.end() && mp2[t[i]] != s[i]) return false;
        //     mp1[s[i]]=t[i];
        //     mp2[t[i]]=s[i];
        // }
        // return true;
        unordered_map<char , char > mp1 ; 
        unordered_map<char , char > mp2 ; 

        int m = s.length();
        for (int i = 0 ; i < m ; i ++){
            char ch1 = s[i];
            char ch2 = t[i];
             
             if (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || 
                 mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1 ){
                return false ;
             }
             mp1[ch1] = ch2;
             mp2[ch2] = ch1; 
        }
        return true;

    }
};