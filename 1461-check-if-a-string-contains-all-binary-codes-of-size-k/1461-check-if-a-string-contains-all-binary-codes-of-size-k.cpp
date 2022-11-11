class Solution {
public:
    bool hasAllCodes(string str, int k) {
        if(str.size()<k) return false;
        unordered_set<string> s;
        for(int i=0; i<=str.size()-k; i++) {
            s.insert(str.substr(i,k));
        }
        return s.size()==pow(2,k);
    }
};