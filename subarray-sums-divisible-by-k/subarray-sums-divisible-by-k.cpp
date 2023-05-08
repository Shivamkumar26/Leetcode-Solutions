class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0, ans = 0;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            sum += arr[i];
            (sum%k<0) ? mp[(sum%k)+k]++ : mp[(sum%k)]++;
        }
        
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            if(i->first==0) ans+=((i->second*(i->second+1))/2);
            else ans+=((i->second*(i->second-1))/2);
        }
        return ans;
    }
};