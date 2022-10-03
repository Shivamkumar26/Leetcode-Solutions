class Solution {
public:
    bool equalFrequency(string word) {
    vector<int>  ans(26);
    for(auto i: word) ans[i-'a']++; //freq
        
    for(int i=0; i<26; i++){ 
        if(ans[i]<=0) continue;
        
        ans[i]--; 
        bool chk = 1;
        int maxi = *max_element(ans.begin(),ans.end());
        for(int j=0; j<26;j++) 
            if(ans[j] && ans[j] != maxi) chk = 0;
        if(chk==1) return 1;  
        ans[i]++; 
    }
    return 0; 
    }
};