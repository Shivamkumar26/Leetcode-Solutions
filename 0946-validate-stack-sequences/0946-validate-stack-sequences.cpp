class Solution {
public:
    bool validateStackSequences(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        stack<int> s;
        int i=0, j=0;
        while (i<n) {
            s.push(a1[i]);
            while (j<n && s.size() && s.top()==a2[j]) {
                s.pop();
                j++;
            }
            i++;
        }
        return (s.size()==0) && (i>=n-1) && (j>=n-1) ? true : false;
    }
};