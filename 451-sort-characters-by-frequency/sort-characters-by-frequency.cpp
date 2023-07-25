class Solution {
    // see video in notes for explaination
    class comp {
        public :
            bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
                return a.second < b.second; 
            }
    };
public:
    string frequencySort(string s) {
        // char, int 
        // sort on the basis of max int 

        // map each char with freq
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;

        // sort in priority queue
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        for(auto it: mp)  {
            pair<char, int> p = {it.first, it.second};
            pq.push(p);
        }

        // making ans;
        int i = 0;
        while(pq.size()) {
            char c = pq.top().first;
            int f = pq.top().second;
            while(f) {
                s[i++] = c;
                f--;
            }
            pq.pop();
        }
        return s;
    }
};