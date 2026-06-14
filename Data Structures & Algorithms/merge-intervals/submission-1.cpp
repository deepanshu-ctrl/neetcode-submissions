class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        map<int,int>mp;
        for(auto x:iv){
            mp[x[0]]++;
            mp[x[1]]--;
        }
        vector<vector<int>> ans;
        vector<int> v;
        int h=0;
        for(auto [i,cnt]:mp){
            if(v.empty()) v.push_back(i);
            h+=cnt;
            if(h==0){
                v.push_back(i);
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};
