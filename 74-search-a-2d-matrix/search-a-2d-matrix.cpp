class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int l = 0, r = mat.size()*mat[0].size()-1, m = mat[0].size();
        while(l!=r) {
            // int mid = l + (r-l)/2;
            int mid = (l+r-1)/2;
            if(mat[mid / m][mid % m] == target) return 1;
            if(mat[mid / m][mid % m] < target)
                l = mid+1;
            else r = mid;
        }
        return mat[r / m][r % m] == target;
    }
};