//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)
    {
        vector<int> vowel(26,0), cons(26,0);
        int vcount = 0, ccount = 0;
        int vsmall = 1000, csmall = 1000;
        
        for(int i=0; i<n; i++) {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
                vowel[s[i]-'a']++;
                vcount++;
                vsmall = min(vsmall, s[i]-'a');
            }
            else {
                cons[s[i]-'a']++;
                ccount++;
                csmall = min(csmall, s[i]-'a');
            }
        }
        
        if(abs(vcount-ccount) > 1) return "-1";
        
        bool isVowel = false;
        if(vcount > ccount) isVowel = true;
        else if(vcount < ccount) isVowel = false;
        else  {
            if(vsmall < csmall) isVowel = true;
            else isVowel = false;
        }
        
        int i=0, j=0, k=0;
        while(i<26 && j<26) {
            if(isVowel) {
                while(i<26 && vowel[i]==0) i++;
                if(i==26) break;
                s[k] = i+'a';
                vowel[i]--;
                isVowel = false;
            }
            else {
                while(j<26 && cons[j]==0) j++;
                if(j==26) break;
                s[k] = j+'a';
                cons[j]--;
                isVowel = true;
            }
            k++;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends