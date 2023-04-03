class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l=0, h=people.size()-1, boats=0;
        while(l<=h) {
            if(people[l] + people[h] <= limit) l++;
            h--;
            boats++;
        }
        return boats;
    }
};