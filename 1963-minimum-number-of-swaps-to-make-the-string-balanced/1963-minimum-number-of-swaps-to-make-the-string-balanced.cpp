class Solution {
public:
    int minSwaps(string s) {
        int n=s.size(), i=0;
        stack<int> st;
        
        while(i<n) {
            if(s[i]=='[') st.push(s[i]);
            else if(st.size()) st.pop();
            i++;    
        }
        //cout << "stack size - " << st.size() << endl;
        return ((st.size()+1)/2);
    }
};

/*

no. of unsorted + 1/2

"[]]][["

*/