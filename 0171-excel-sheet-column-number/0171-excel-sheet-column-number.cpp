class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), ans = 0;
        int po = 0;
        for(int i = n-1; i>=0; i--) {
            ans = ans + (columnTitle[i]-'A'+1)*(pow(26, po));
            po++;
        }
        return ans;
    }
};
/**

1*1

2*1+26*1

25*1+26*26

1*1+26*3+3*26*26

**/