class Solution
{
    public:
        string minWindow(string s, string t)
        {
            int m = s.size(), n = t.size();
            int ans = INT_MAX, start = 0;
            unordered_map<char, int> mp;

            for (auto x: t) mp[x]++;

            int count = mp.size();
            int i = 0, j = 0; // i = window_start, j = window_end

            while (j < s.length())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0) count--;

                if (count == 0) {
                    while (count == 0) {
                        if (ans > j - i + 1) {
                            ans = j - i + 1;
                            start = i;
                        }
                        mp[s[i]]++;
                        if (mp[s[i]] > 0) count++;
                        i++;
                    }
                }
                j++;
            }
            return ans != INT_MAX ? s.substr(start, ans) : "";
        }
};