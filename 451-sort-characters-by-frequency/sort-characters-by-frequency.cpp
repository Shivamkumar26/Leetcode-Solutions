class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        
        for(int i=0; i<n; i++) mp[s[i]]++;
        for(auto i=mp.begin(); i!=mp.end(); i++) 
            pq.push({i->second, i->first});
        
        s="";
        while(pq.size()) {
            char ch = pq.top().second;
            int freq = pq.top().first;
            while(freq--) s+=ch;
            pq.pop();
        }
        return s;
    }
};

/*

freq store

A - 1 
a - 1
b - 2


2-b
1-A
1-a

*/