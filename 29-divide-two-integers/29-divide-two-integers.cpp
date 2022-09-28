class Solution {
public:
    int divide (int m, int n) {
        if(m==0) return 0;
        bool psign = true;
        
        long long a=m, b=n;
        if(a<0 && b<0) psign = true; 
        else if(a<0 || b<0) psign = false;
        
        long long ans = 0, sum = 0;
        a = abs(a); b = abs(b);
        
        if(b==1) {
        if(psign) return (a<INT_MIN || a>INT_MAX) ? INT_MAX : a;
            return -1*a;
        }
        if(a < b) return 0;
        while(a >= sum) {
            sum += b;
            ans++;
            //cout << "ans sum " << ans << " " << sum << endl;
        }
        ans--;
        //cout << " ans " << ans << endl;
        if(psign) {
            if(ans > INT_MAX) return INT_MAX;
        }
        else ans=(-1)*ans;
        return ans;
    }
};