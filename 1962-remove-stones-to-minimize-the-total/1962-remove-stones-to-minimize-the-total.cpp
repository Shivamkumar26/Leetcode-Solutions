class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n = piles.size(), sum = 0;
        for(int i=0; i<n; i++) {
            pq.push(piles[i]);
            sum += piles[i];
        }
        
        for(int i=0; i<k; i++) {
            sum -= (pq.top()/2);
            pq.push(pq.top() - (pq.top()/2));
            pq.pop();
            //cout << sum << " " <<endl;
        }
        return sum;
    }
};