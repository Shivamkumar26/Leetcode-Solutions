class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int size = tasks.size();
        unordered_map<int, int> mp;
        for(int i=0; i<size; i++) {
            mp[tasks[i]]++;
        }

        int numberOfRounds = 0;
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            if(i->second == 1) return -1;
            numberOfRounds += (i->second/3);
            if(i->second % 3) numberOfRounds++;
        }
        return numberOfRounds;
    }
};