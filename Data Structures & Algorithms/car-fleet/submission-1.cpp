class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int,int>> pair;
        for(int i=0;i<p.size();i++){
            pair.push_back({p[i],s[i]});
        }
        sort(pair.rbegin(),pair.rend());
        vector<double> ans;
        for(auto x:pair){
            ans.push_back(double(target-x.first)/x.second);
            if(ans.size()>=2 && ans.back()<=ans[ans.size()-2]) ans.pop_back();
        }
        return ans.size();
    }
};