class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ans = "";
        int n = s.length();
        
        // 2*(numRows-(i+1))
        for(int i = 0; i < numRows; i++) {
            for(int j = i; j < n; j += 2*(numRows-1)) {
                ans += s[j];
                if(i>0 && i<numRows-1 && j+2*(numRows-(i+1)) < n)  
                    ans += s[j+2*(numRows-(i+1))];
            }
        }
        return ans;
    }
};