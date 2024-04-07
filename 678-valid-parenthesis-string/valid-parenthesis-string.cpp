class Solution {
public:
 bool checkValidString(string s) {
        int n = s.size();

        stack<int> st1, st2;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st1.push(i);
            else if(s[i]=='*') st2.push(i);
            else {
                if(st1.size()) st1.pop();
                else if(st2.size()) st2.pop();
                else return false;
            }
        }

        while(st1.size()){
            if(st2.size() && st2.top() > st1.top()) {
                st1.pop();
                st2.pop();
            } else return false;
        }
        return true;
    }
};
/*
" * ( ) ) " -> true
" ( ( ( ) * * " -> true
"((**))" -> true
o - 1
c - 2
s - 1

o + s >= c

"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"

*/