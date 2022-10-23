class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         vector <int> countn(nums.size(),0);
    for (int i=0; i<nums.size(); i++) {
        countn[nums[i]-1] ++;
    }

    int missing = 0, repeating = 0;
    vector <int> ans;
    for (int i=0; i<nums.size(); i++) {
        if (countn[i]==0) {
            missing = i+1;
        }
        if (countn[i]>1) {
            repeating = i+1;
        }
    }
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
    }
};