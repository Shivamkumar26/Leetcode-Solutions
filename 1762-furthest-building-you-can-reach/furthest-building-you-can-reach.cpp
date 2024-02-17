class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=1; i<n; i++) {
            int gap = heights[i] - heights[i-1];
            
            if(gap > 0) pq.push(gap);
            if(pq.size() > ladders) { //use bricks
                bricks -= pq.top();
                pq.pop();
            }
            if(bricks < 0) return i-1;
        }
        return n-1;
    }
};
/*


dp will give tle based on constraints

I can store gaps 
as long as my elements size stored in queue < ladders count 
if they become equal or exceed -> use bricks

if no bricks left thn we cant move more



8
0
5
0
15
2
0
16


*/