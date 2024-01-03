class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), ans = 0;
        if(n==0) return ans;
        vector<int> count;
        for(int i=0; i<n; i++) {
            int lc = 0;
            for(int j=0; j<bank[i].size(); j++) {
                if(bank[i][j]=='1') lc++;
            }
            if(lc) count.push_back(lc);
        }
        if(count.size()==0) return ans;
        
        int start = count[0];
        for(int i=1; i<count.size(); i++) {
            ans += start*count[i];
            start = count[i];
        }
        return ans;
    }
};
/*


ans += 3*2 + 2*1 = 8


*/