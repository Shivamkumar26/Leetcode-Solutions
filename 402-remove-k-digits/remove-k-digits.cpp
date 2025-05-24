class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size();
        stack<int> st;
        int i = 0;

        while(i<n) {
            while(st.size() && k > 0 && st.top() > num[i]-'0') {
                k--;
                st.pop();
            }
            st.push(num[i]-'0');
            i++;
        }
        //string is in increasing order ie. 1234
        while(k) {
            st.pop();
            k--;
        }


        if(st.size() == 0) return "0";

        while(st.size()){
            res.push_back(st.top()+'0');
            st.pop();
        }
        //trailing zero
        while(res.size() && res.back() == '0') {
            res.pop_back();
        }

        if(res == "") return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};