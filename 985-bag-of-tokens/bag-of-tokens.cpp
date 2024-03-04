class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int power) {
        int n = nums.size();
        int maxScore = 0, score = 0, l=0, r=n-1;
        
        sort(nums.begin(), nums.end());
        while(l <= r) {
            if(nums[l] <= power) {
                score++;
                power -= nums[l++];
            }
            else {
                if(score==0) return maxScore;
                score--;
                power += nums[r--];
            }
            maxScore = max(score, maxScore);
        }
        return maxScore;
    }
};
/*

l and right 
score++ power-=nums[l++]
score-- power+=nums[r--]


return maxscore

*/