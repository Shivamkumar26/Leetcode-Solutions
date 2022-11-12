class Solution {
public:
    int characterReplacement(string s, int k) {
          unordered_map<char, int> mp;
		    int st = 0, ans = 0, maxsimilarchar = 0;
		    for(int e=0; e<s.size(); e++) {
		        mp[s[e]]++;
		        maxsimilarchar = max(maxsimilarchar, mp[s[e]]);
		        int diffchar = (e-st+1)-maxsimilarchar;
		        
		        if(diffchar>k){
		            mp[s[st]]--;
		            st++;
		        }
		        ans = max(ans, e-st+1);
		    }
		    return ans;
    }
};