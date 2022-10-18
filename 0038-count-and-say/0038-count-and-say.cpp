class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string s = countAndSay(n-1); // "1"
        string ans = "";
        int freq = 0;
        char c = ' ';
        for(int i=0; i<s.size(); i++) { 
            if(i==0 || c==s[i]) {
                freq++;
                c = s[i];
            }
            else {
                string temp;
                temp.append(1, c);
                ans += to_string(freq) + temp;
                freq = 1;
                c = s[i];
            }
        }
        string temp;
        temp.append(1, c);
        ans += to_string(freq) + temp;
        return ans;
    }
};

/*

base - 
f(1) n = 1 ans  = "1"

freq + num

f(2) = f("1") = "11"
f(3) = f("11") = "21"
f(4) = f("21") = "1211"
.
.
.
f(i) = f(i-1) = string(freqcount + num)

*/
