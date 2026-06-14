class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto x:strs){
            vector<int> cnt(26,0);
            for(auto c:x){
                cnt[c-'a']++;
            }
            string k=to_string(cnt[0]);
            for(int i=1;i<26;i++){
                k+=','+to_string(cnt[i]);
            }
            mpp[k].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
