class Solution
{
    struct comp
    {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        }
    };
    
    public:
        vector<string> topKFrequent(vector<string> &nums, int k)
        {
            int n = nums.size();

            unordered_map<string, int> freq;
            for (int i = 0; i < n; i++) freq[nums[i]]++;

            priority_queue<pair<int, string>, vector< pair<int, string>>, comp> pq;
            for (auto i = freq.begin(); i != freq.end(); i++)
            {
                pq.push({ i->second, i->first });
                if (pq.size() > k) pq.pop();
            }

            vector<string> ans;
            while (pq.size()) {
                ans.insert(ans.begin(), pq.top().second);
               	// ans.push_back(pq.top().second);
                pq.pop();
            }
           	// reverse(ans.begin(), ans.end());
            return ans;
        }
};