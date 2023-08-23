class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for(int i=0; i<n; i++) mp[s[i]]++;
        for(auto i: mp) pq.push({i.second, i.first});

        string ans = "";
        while(pq.size() > 1) {
            auto m1 = pq.top();
            pq.pop();
            auto m2 = pq.top();
            pq.pop();

            ans += m1.second;
            ans += m2.second;
            m1.first--;
            m2.first--;

            if(m1.first) pq.push(m1);
            if(m2.first) pq.push(m2);
        }
        if(pq.size()==1) {
            if(pq.top().first-1 > 0) return "";
            ans += pq.top().second;
        }
        return ans;
    }
};
/*

a a a a b b b c c c 

acbcacbaba


bababaa

a-4
b-3
c-3

abababa

cbcbcb

acacacaca

a-1
b-0
c-0

abcabcabca


aaaabbbbb

ba b ab cac ac


*/