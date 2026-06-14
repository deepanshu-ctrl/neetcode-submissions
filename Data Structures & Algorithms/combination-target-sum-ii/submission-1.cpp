class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        ans.clear();
        sort(cand.begin(),cand.end());
        vector<int> sb;
        solve(cand,t,sb,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    void solve(vector<int> &cand,int t,vector<int> &sb,int i){
        if(t==0){
            ans.insert(sb);
            return;
        }
        if(t<0 || i>=cand.size()) return;
        sb.push_back(cand[i]);
        solve(cand,t-cand[i],sb,i+1);
        sb.pop_back();
        solve(cand,t,sb,i+1);
    }
};
