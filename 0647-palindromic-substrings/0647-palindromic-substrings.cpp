class Solution {
public:
    int countSubstrings(string s) {
        int ans=0, n=s.size();
        for(int i=0; i<n; i++, ans++) {
            int back = i-1, front = i+1;
            while(back>=0 && front<n && s[back--]==s[front++]) 
                ans++;
            
            back = i, front = i+1;
            while(back>=0 && front<n && s[back--]==s[front++]) 
                ans++;
        }
        return ans;
    }
};