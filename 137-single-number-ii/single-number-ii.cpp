class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<32; i++) {
            int count = 0; //on bits kitni h
            int num = 1<<i;
            for(int j=0; j<n; j++) {
                if(num & nums[j]) count++;
            }
            if(count % 3) ans |= num;
        }
        return ans;
    }
};

/*

total ele = 3n+1

41

vector 32 bits





000
111
1100011



*/