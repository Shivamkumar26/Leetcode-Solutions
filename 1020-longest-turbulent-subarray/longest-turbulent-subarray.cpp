class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 0, len = 0;
        for(int i = 0; i < n; i++) {
            if(i > 1 && 
               ((arr[i-2] > arr[i-1] && arr[i-1] < arr[i]) || 
                (arr[i-2] < arr[i-1] && arr[i-1] > arr[i]))) 
                len++;
            else if(i>=1 && arr[i-1]!=arr[i]) len = 2;
            else len = 1;
            res = max(res, len);
        }
        return res;
    }
};