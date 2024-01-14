class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currFuel = 0, allFuel = 0, start = 0;
        
        for(int i=0; i<n; i++) {
            currFuel += (gas[i]-cost[i]);
            allFuel += (gas[i]-cost[i]);
            
            if(currFuel < 0) currFuel = 0, start = i+1;
        }
        return allFuel < 0 ? -1 : start;
    }
};