class Solution {
public:
    int minOperations(int k) {
        if(k<=1) return 0;
        int ans = k, c=1;
        for(int i=1; i<=k/2+1; i++) {
            c++;
            ans = min(ans, k/c + ((k%c==0) ? 0 : 1) + c-1-1);
            cout << ans << " ";
        }
        return ans;
    }
};
/*

k = 11

5 + 


*/