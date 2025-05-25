class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int p) {
        if(st.size() == 0 || st.top().first > p) {
            st.push({p, 1});
        }
        else {
            int ct = 1;
            while(st.size() && st.top().first <= p) {
                ct += st.top().second;
                st.pop();
            }
            st.push({p, ct});
        }
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */