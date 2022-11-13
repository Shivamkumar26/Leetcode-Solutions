class Solution {
public:
    string reverseWords(string s) {
        // int n=s.size();
        // int st=0, e=0;
        // while(e<n) {
        //     while(e<n && s[e]!=' ') e++;
        //     reverse(s.begin()+st, s.begin()+e);
        //     st=e+1; e++;
        //     //cout<< s << endl;
        // }
        // reverse(s.begin(),s.end());
        // return s;
        
        int sz = s.size();
        int i = 0, j = 0;
        while (i<sz) {
            while (i<sz && s[i]==' ') i++; // start with space
            if (i<sz && j>0) s[j++] = ' '; //adding space after a word
            int startWordwise = j; //new word start
            while (i<sz && s[i]!=' ') s[j++] = s[i++]; //check like sliding w
            reverse(s.begin()+startWordwise, s.begin()+j);
        }
        s.resize(j); //sinjce first j elements are ans
        reverse(s.begin(), s.end());
    return s;
    }
};