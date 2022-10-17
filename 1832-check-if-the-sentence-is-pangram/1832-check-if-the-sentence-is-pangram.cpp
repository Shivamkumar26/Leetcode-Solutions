class Solution
{
    public:
        bool checkIfPangram(string s)
        {
            vector<bool> alphacheck(26);
            for (int i = 0; i < s.size(); i++)
            {
                alphacheck[s[i] - 'a'] = 1;
            }
            for (int i = 0; i < 26; i++)
            {
                if (alphacheck[i] == 0) return false;
            }
            return true;
        }
};