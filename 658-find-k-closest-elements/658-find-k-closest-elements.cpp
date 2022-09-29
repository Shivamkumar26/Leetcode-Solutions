class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int sz, int e) {
        int n = arr.size(), l = 0, r = n-1;
        while(r-l>=sz) {
            if(e - arr[l] <= arr[r] - e) r--;
            else l++;
        }
        vector<int> sol;
        for(int i=l; i<=r; i++) sol.push_back(arr[i]);
        return sol;
    }
};