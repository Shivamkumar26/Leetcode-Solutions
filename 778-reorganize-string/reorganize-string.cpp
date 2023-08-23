class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for(int i=0; i<n; i++) mp[s[i]]++;
        for(auto i: mp) pq.push({i.second, i.first});

        string ans = "";

        auto block = pq.top();
        pq.pop();
        ans += block.second;
        block.first--;
        while(pq.size()) {
            auto temp = pq.top();
            ans += temp.second;
            temp.first--;
            pq.pop();
            if(block.first > 0)
                pq.push(block);
            block = temp;
        }
        if(block.first > 0) return "";
        return ans;
    }
};