class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int moreRocks) {
        int n = rocks.size();
        vector<int> diff(n);
        for(int i=0; i<n; i++)
            diff[i] = capacity[i] - rocks[i];
        sort(diff.begin(), diff.end());
        int ans = 0;
        for(int i=1; i<n; i++) {
            diff[i] += diff[i-1];
            ans = i;
            if(moreRocks < diff[i]) break; 
        }
        return moreRocks < diff[ans] ? ans : n;
    }
};
/**

[91,54,63,99,24,45,78]
[35,32,45,98,6,1,25]
17




100

10 2 2 
2 2 0 

8 0 2  diff array
0 2 8 sort



**/