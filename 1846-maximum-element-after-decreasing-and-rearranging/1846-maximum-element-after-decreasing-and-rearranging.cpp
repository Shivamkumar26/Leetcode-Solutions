class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int pre=0;
        for(int i=0; i<n; i++) 
            pre = min(pre+1, arr[i]);
        return pre;
    }
};

/*

arr[0]=1
adj <= 1; arr[i]-arr[i-1]<=1

1. decrease

1, 2, 2
*/