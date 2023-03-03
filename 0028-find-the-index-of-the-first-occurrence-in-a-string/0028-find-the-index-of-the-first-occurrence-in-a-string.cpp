class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle) == haystack.find("--") ? -1 : haystack.find(needle);
    }
};