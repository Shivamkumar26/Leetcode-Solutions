class Solution {
    int gcd(int a, int b)  {  
    if (a == 0)   return b; 
    if (b == 0)   return a;   
    if (a == b)   return a; 
    
    if (a > b) return gcd(a-b, b);  
    return gcd(a, b-a);  
}  
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            // if(nums[i]==k) ans++;

            int gcdtillnow=nums[i];
            for(int j=i; j<nums.size(); j++) {
                if(nums[j]<k || gcdtillnow<k) break;
                gcdtillnow = gcd(gcdtillnow, nums[j]);
                if(nums[j]%k!=0) continue;
                else if(gcdtillnow==k)  ans++;
            }
        }
        return ans;
    }
};

/*

[9,3,1,2,6,3]
3
[4]
7
[1]
1
[2,1]
1
[5,1,15,11,12,14,12,9]
12


Input: nums = [9,3,1,2,6,3], k = 3
Output: 4
Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]

*/