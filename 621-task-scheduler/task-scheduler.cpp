class Solution {
public:
    int leastInterval(vector<char>& nums, int k) {
        int n = nums.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;

        priority_queue<int> pq;
        for(auto i=mp.begin(); i!=mp.end(); i++)
        pq.push(i->second);

        int ans = 0;
        while(pq.size()) {
            vector<int> v;
            for(int i=0; i<=k; i++) {
                if(pq.size()==0) break;
                int fq = pq.top();
                pq.pop();
                fq--;
                v.push_back(fq);
            }
            for(int i=0; i<v.size(); i++) if(v[i]>0) pq.push(v[i]);

            if(pq.size()) ans += (k+1);
            else ans += v.size();
        }
        return ans;
    }
};
/*

tasks - map

sort map acc. to freq
mf mf2 mf3 


cooling period = (no. of rest elements-n)>=0 : nore-n

min ans - size of tasks

a-2
b-2
c
d


*/