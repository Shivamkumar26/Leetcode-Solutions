class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> mp;
        
        queue<string> q;
        q.push(start);
        mp.insert(start);
        
        int steps=0;
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                string str = q.front();
                q.pop();
                if(str == end) return steps;
                string ch = "ACGT";
                
                for(int c = 0; c<4; c++) {
                for(int j=0; j<8; j++) {
                    string s = str;
                    
                        s[j] = ch[c];
                        if(mp.count(s)==0 && find(bank.begin(), bank.end(), s)!=bank.end()) {
                            q.push(s);
                            mp.insert(s);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};