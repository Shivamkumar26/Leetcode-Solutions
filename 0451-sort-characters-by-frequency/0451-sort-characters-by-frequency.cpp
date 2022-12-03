class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        
        for(int i=0; i<s.size(); i++)
            mp[s[i]]++;
        for(auto i=mp.begin(); i!=mp.end(); i++) 
            pq.push({i->second, i->first});
        
        int i = 0;
        while(pq.size()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            
            while(freq--) s[i++] = ch;
            pq.pop();
        }
        return s;
    }
};

/***

treemapp
e,p-2 
m,a,r,t-1

------------------------------
unordered_map<char, int> mp;
priority_queue<int> pq;

// freq map
for(int i=0; i<s.size(); i++) mp[s[i]]++;

// storing freq to priority queue
for(auto i=mp.begin(); i!=mp.end(); i++) 
    pq.push(mp.second);

while(pq.size()) {
    int i = pq.top();
    pq.pop();

    while(i--) s[i]=
}
return s;

***/