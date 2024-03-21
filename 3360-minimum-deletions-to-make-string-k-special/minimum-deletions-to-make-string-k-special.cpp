class Solution {
public:
    int minimumDeletions(string word, int k) {
        int m = word.size();
        vector<int> v(26, 0);

        for(int i=0; i<m; i++) v[word[i]-'a']++;
        sort(v.begin(), v.end());

        int n = v.size(), ans = m, sum = 0;
        for(int i=0; i<n; i++) {
            if(v[i]==0) continue;
            int t = sum;
            for(int j=i+1; j<n; j++) {
                if(v[j] > v[i]+k) t += (v[j]-v[i]-k);
            }
            ans = min(t, ans);
            sum += v[i];
        }
        return ans;
    }
};
/*

"zzfzzzzppfp"

2
3
6


"dabdcbdcdcd"

d-5
a-1
b-2
c-3

2
5 1 2 3 

 2 3 5

2 1

r - (l + k) 

2 3 4

-2 -1
a-2


1 2 4
0 2 2
(k)


a-6
b-1

k=2


*/