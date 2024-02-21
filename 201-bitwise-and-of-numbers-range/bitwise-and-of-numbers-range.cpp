class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = right;
        while(left < res) {
            res = res & (res-1);
        }
        return res;
    }
};
/*

bits[32] = {0};

5 6 7

101
110
111

*/