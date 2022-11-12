//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
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
		/*
		
s = "AABABBA", k = 1
Output: 4
		
		*/
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends