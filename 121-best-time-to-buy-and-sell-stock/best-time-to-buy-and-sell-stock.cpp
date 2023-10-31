class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = prices[0], s = -1, mx = 0;
        for(int i=1; i<prices.size(); i++) {
            s = max(s, prices[i]);
           if(b > prices[i]) {
               b = prices[i];
               s=-1;
           }
            mx = max(mx, s-b);
        //cout << "b s mx " << b << " " << s << " " << mx << endl;
        }
        return mx;
    }
};

/*

7 1 5 3 6 4
  b     s

buy -> minimize 
sell -> maximize
buy should come before sell

*/