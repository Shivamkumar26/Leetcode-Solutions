class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ans(n, -1);

        queue<int> q;
        for(int i=0; i<n; i++) q.push(i);
       
        for(int i=0; i<n; i++) {
            ans[q.front()] = deck[i];
            q.pop();
            if(q.size()) {
                q.push(q.front());
                q.pop();
            }
        }
        
        return ans;
    }
};
/*

sorting 
2 3 5 7 11 13 

size-1/2+1 - 3 +1 = 4

2 11 3 


*/