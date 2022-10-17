class Solution
{
    bool isPossible(vector<int> &nums2, int target)
    {
        vector<long> nums(nums2.begin(), nums2.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (target < nums[i]) return false;
            nums[i + 1] = nums[i + 1] - target + nums[i];
        }
        if (nums[nums.size() - 1] <= target) return true;
        return false;
    }
    public:
        int minimizeArrayValue(vector<int> &nums)
        {
            int low = 0, high = 1e9;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (isPossible(nums, mid))
                {
                    high = mid;
                }
                else low = mid + 1;
            }
            return low;
        }
};