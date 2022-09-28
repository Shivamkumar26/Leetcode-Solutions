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
    
    string multiply(string a, string b) {
        int n = a.size()-1, m = b.size()-1;
        string ans = "";
        
        for(int i = n; i >= 0; i--) {
            int carry = 0;
            int n1 = a[i]-'0';
            string temp = ""; 
            for(int j = m; j >= 0; j--) {
                int n2 = b[j] - '0';
                int prod = n1*n2 + carry;
                
                temp += (prod%10 + '0'); 
                carry = prod/10;
            }
            if(carry != 0) temp += (carry + '0');
            reverse (temp.begin(), temp.end());
            int m = i;
            while (n-1 >= m++) temp += '0';
            //cout << "temp - " << temp << endl;
            ans = add(ans, temp);
            //cout << "ans - " << ans << endl;
        }
        
        //remove trailing 0 from ans
        int size = ans.size(), it = 0;
        while (it < size-1) {
            while(it<size-1 && ans[it]=='0') it++;
            break;
        }
        ans = ans.substr(it, size-it);
        return ans;
    }
};