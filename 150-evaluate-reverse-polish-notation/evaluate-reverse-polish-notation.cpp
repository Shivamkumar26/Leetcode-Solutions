#define ll long long 
class Solution {
public:
    int evalRPN(vector<string>& nums) {
        ll ans = 0;
        stack<ll> st;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]=="+" || nums[i]=="-" || nums[i]=="*" || nums[i]=="/") {
                ll n1 = st.top(); st.pop();
                ll n2 = st.top(); st.pop();
                ans = 0;
               
                if (nums[i] == "+") ans = n1 + n2;
                else if (nums[i] == "-") ans = n2 - n1;
                else if (nums[i] == "*") ans = n1 * n2;
                else if (nums[i] == "/") ans = n2 / n1;
                st.push(ans);
            }
            else {
                int num = stoi(nums[i]);
                st.push(num);
            }
        }
        
        return (int)st.top();
    }
};

/*





*/