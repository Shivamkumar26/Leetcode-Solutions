class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int i=0, n=costs.size(), ic=0;
        sort(costs.begin(), costs.end());
        
        while(i<n) {
            if(costs[i]<=coins) {
                ic++;
                coins-=costs[i];
                i++;
            }
            else break;
        }
        return ic;
    }
};

/*

[7,3,3,6,6,6,10,5,9,2]
56
[6,2,8,8,5,6,6,2,2,2]
77


*/