class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        for(int i=0; i<str.size(); i++) {
            if(!s.empty() && s.top()==str[i])
                s.pop();
            else {
                s.push(str[i]);
            }
        }
        string ans = "";
        while(s.size()) {
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};