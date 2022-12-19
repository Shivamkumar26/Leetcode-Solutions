class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        if(x<0) {
            positive = false;
            x = abs(x);
        }
        int ans = 0, temp = x;
        while(temp>0) {
            int rem = temp%10;
            if(ans> INT_MAX/10) return 0;
            ans = ans*10 + rem;
            temp /= 10;
        }
        if(positive) return ans;
        return -1*ans;
    }
};