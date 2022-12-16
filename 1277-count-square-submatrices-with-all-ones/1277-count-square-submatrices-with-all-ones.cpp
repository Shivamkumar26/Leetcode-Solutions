class Solution {
    // int check(vector<vector<int>>& nums, int r, int c) {
    //     int count = 0;
    //     int side = 2;
    //     while(1) {
    //         r++; c++;
    //         if(r==nums.size() || c==nums[0].size()) break;
    //         for(int i=r; i>r-side; i--) {
    //             if(nums[i][c]==0) break;
    //         }
    //         for(int i=c; i>c-side; i--) {
    //             if(nums[r][i]==0) break;
    //         }
    //         count++;
    //         side++;
    //     }
    //     return count;
    // }
public:
    int countSquares(vector<vector<int>>& nums) {
        // int n = nums.size();
        // int m = nums[0].size();
        // int ans = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(nums[i][j]==1) { 
        //             ans++;
        //             ans += check(nums, i, j); 
        //         }
        //         cout << " i j ans " << i << " - " << j << " ans - " << ans << endl;
        //     }
        // }
        // return ans;
        
        
        
        int n = nums.size();
        int m = nums[0].size();
        int ans=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i>0 && j>0 && nums[i][j]>0) {
                   nums[i][j] = min({nums[i-1][j] , nums[i][j-1] , nums[i-1][j-1]})+1; 
                }
                ans += nums[i][j];
            }
        }
        return ans;
    }
}; 
/**

[[0,0,0],
[0,1,0],
[0,1,0],
[1,1,1],
[1,1,0]]

**/

/**


0 1 1 1
1 1 1 1 
0 1 1 1 

down - d
0 3 2 1 
4 3 2 1 
0 3 2 1 

right r
0 3 3 3 
1 2 2 2 
0 1 1 1 

sum of min(r, d)
0 3 2 1 
1 2 2 1 
0 1 1 1 



1 0 1 
1 1 0
1 1 0


3 0 1 
2 2 0 
1 1 0


1 0 1
2 1 0
2 1 0

**/