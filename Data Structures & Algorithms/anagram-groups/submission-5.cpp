class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto x:strs){
            string temp=x;
            sort(x.begin(),x.end());
            mpp[x].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto x:mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
