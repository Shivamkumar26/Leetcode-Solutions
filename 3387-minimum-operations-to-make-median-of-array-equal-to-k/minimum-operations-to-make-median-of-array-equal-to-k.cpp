class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = n/2;

        long long ans = 0;

        if(nums[mid]==k) return 0;
        else if(nums[mid] > k) {
            while(mid >=0 && nums[mid] > k) {
                ans += (nums[mid]-k);
                mid--;
            }
        }
        else {
            while(mid < n && nums[mid] < k) {
                ans += (k - nums[mid]);
                mid++;
            }
        }
        return ans;
    }
};

/*


k = 4
pos = 3

2 5 5 6 8


middle 
if(mid > k) 
left k ele greater than k -> equal to k

else if(mid < k)
right k ele smaller than k -> equal to k



k = 7
pos = 3
2 5 5 6 8
ans+=7


k = 4
pos = 4
1 2 3 4 5 6 



*/