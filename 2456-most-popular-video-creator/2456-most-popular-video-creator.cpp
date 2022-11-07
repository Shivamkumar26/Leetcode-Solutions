class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& crt, vector<string>& ids, vector<int>& vws) {
        unordered_map<string,long> tot; //storing creator views
        unordered_map<string,vector<pair<long,string>>> vid; //storing creator views id
        
        long m = 0; //max views
        for (int i = 0; i < crt.size(); i++) {
            tot[crt[i]] += vws[i]; 
            m = max(m, tot[crt[i]]); //max views
            vid[crt[i]].emplace_back(-vws[i], ids[i]);
        }
        
/*
             vid[crt[i]] = {{-vws[i], ids[i]}};
             will give WA because emplace back says if element is present in map then dont change its value. But line 14 says the value which comes late will be stored.         
*/
        
        vector<vector<string>> result;
        for (auto i : vid) {
            if (tot[i.first] != m) continue;
            //lexo small ele
            string small = min_element(i.second.begin(),i.second.end())->second;
            result.push_back({i.first, small});
        }
        return result;
    }
};

/*

- kis creator k pass max views/popularity hai 
- pq views,creator 

*/
