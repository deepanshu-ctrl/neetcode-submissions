class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> ans;
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>> ans;
        for(auto x: strs){
            vector<int> cnt(26,0);
            for(char c:x){
                cnt[c-'a']++;
            }
            string k=to_string(cnt[0]);
            for(int i=1;i<26;i++){
                k+=','+to_string(cnt[i]);
            }
            mpp[k].push_back(x);
        }
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
        // for(auto x:strs){
        //     string temp=x;
        //     sort(x.begin(),x.end());
        //     mpp[x].push_back(temp);
        // }
        // for(auto x:mpp){
        //     ans.push_back(x.second);
        // }
        // return ans;
    }
};
