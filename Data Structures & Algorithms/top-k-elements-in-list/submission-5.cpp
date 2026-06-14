class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto x:nums) mpp[x]++;
        vector<pair<int,int>>p;
        for(auto x:mpp){
            p.push_back({x.second,x.first});
        }
        sort(p.rbegin(),p.rend());
        vector<int> ans;
        int i=0;
        while(i<k){
            ans.push_back(p[i++].second);
        }
        return ans;
    }
};
