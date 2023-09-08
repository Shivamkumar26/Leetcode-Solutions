class Solution {
public:
    int reverse(int x) {
        bool pos = true;
        if(x<0) { 
            pos = false; 
            x = abs(x); 
        }
        
        int n = x, ans = 0;
        while(n > 0) {
            int rem = n % 10;
            if(ans > INT_MAX/10) return 0;
            ans = ans*10 + rem;
            n/=10;
        }
        
        if(!pos) ans=-1*ans;
        return ans;
    }
};