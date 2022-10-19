class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int p = 0, n = pushed.size();
        stack<int> s;
        for(int i=0; i<n; i++) {
            s.push(pushed[i]);
            while(s.size() && s.top() == popped[p]) {
                s.pop();
                p++;
            }
        }
        return s.size()==0;
    }
};