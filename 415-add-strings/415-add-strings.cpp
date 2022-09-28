class Solution {
public:
     void calc (string &a, int i, string& ans, int& carry) {
         while(i>=0) {
            int n1 = a[i] - '0';
            int sum = n1 + carry;
            ans += (sum%10 + '0');
            carry = sum/10;
            i--;
        }
    }
    
    string add(string a, string b) {
        int i = a.size()-1, j = b.size()-1, carry = 0;
        
        string ans = "";
        
        while(i >= 0 && j >= 0) {
            int n1 = a[i] - '0', n2 = b[j] - '0';
            int sum = n1 + n2 + carry;
            ans += (sum%10 + '0');
            carry = sum/10;
            i--; j--;
        }
        
        calc (a, i, ans, carry);
        calc (b, j, ans, carry);
        if(carry!=0) ans += (carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        return add(num1, num2);
    }
};