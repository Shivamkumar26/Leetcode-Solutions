class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        
        vector<char> v(26);
        for(int i = 0; i < 26; i++) v[i] = 'a' + i;
        
        for(int i = 0; i < n; i++) {
            char toreplace = max(v[s1[i]-'a'], v[s2[i]-'a']);
            char withreplace = min(v[s1[i]-'a'], v[s2[i]-'a']);
            for(int j=0; j<26; j++) 
                if(v[j] == toreplace) v[j] = withreplace;
        }
        
        for(int i=0; i<m; i++) baseStr[i] = v[baseStr[i]-'a'];
        return baseStr;
    }
};


/*

leetcode 
programs

l p 
a c e o r s
g t 
d m

sourcecode
aauaaaaada

ex.
hello 
world

h w 
d e o
l r 

hold
hdld

*/