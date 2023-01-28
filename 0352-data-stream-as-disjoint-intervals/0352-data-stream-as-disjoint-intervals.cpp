class SummaryRanges {
    set<int> st;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int l = -1, r = -1;
        
        for(auto it: st) {
            if(l == -1)         l = it, r = it;
            else if(r+1 == it)  r = it;
            else {
                ans.push_back({l, r});
                l = it, r = it;
            }
        }
        
        ans.push_back({l, r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */