class Solution {
public:
    int getKth(int lo, int hi, int k) {
        int n = hi - lo + 1;
        vector<vector<int>> v;
        
        for(int i=lo; i<=hi; i++) {
            int steps = 0, num = i;
            while(num!=1) {
                if(num % 2) num = num*3+1;
                else num/=2;
                steps++;
            }
            v.push_back({steps, i});
        }
        sort(v.begin(), v.end());
        return v[k-1][1];
    }
};