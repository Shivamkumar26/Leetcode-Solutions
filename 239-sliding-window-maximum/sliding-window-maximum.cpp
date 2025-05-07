class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return {};
        priority_queue<int> pq;
        unordered_map<int, int> mp;

        //adding first k elements in map and pq
        for(int i=0; i<k; i++) {
            pq.push(nums[i]);
            mp[nums[i]]++;
        }

        vector<int> res;
        res.push_back(pq.top()); 
        for(int i=k; i<n; i++) {
            mp[nums[i-k]]--;
            mp[nums[i]]++;
            pq.push(nums[i]);

            //freq of top ele 
            while(mp[pq.top()] == 0) {
                pq.pop();
            }
            res.push_back(pq.top());
        }
        return res;
    }
};
/*

[1,3,1,2,0,5]

[3,3,2,5]

3 
pq 3 1 1
mp
1:1
3:1
1:1 





1 3 -1 -3 5 3 6 7 
  3  3  5 5 6 7

3 3 5 5 6   

3
pq 1 3 -1 

mp 
1:1
3:1
-1:1
 





*/