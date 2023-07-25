class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        // if(n<=3) return -1;

        int l = 0, r = n-1;
        while(r > l) {
            int mid = l + (r-l)/2;
            cout << "l r mid " << l << " " << r << " " << mid << endl;
            if(arr[mid] > arr[mid-1] && (arr[mid] > arr[mid+1])) return mid;
            if(arr[mid] > arr[mid-1] && (arr[mid] < arr[mid+1])) l = mid;
            else r =  mid;
        }
        return -1;
    }
};
// 1 2 3 4 5 4 3 2 1 