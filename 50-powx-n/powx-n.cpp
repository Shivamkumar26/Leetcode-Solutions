class Solution {
public:
    double myPow(double x, int n) {
        bool pos = true;
        long long nn = n;
        if(nn<0) {
            nn *= (-1);
            pos = false;
        }

        double ans = 1.0;
        //TLE
        // for(long long i=0; i<nn; i++) {
        //     ans *= x;
        // }

        while(nn) {
            if(nn % 2) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }

        if(!pos) ans = 1/ans;
        return ans;
    }
};