class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int j,int k,vector<int> &sb,int cnt){
        if(cnt==k){
            ans.push_back(sb);
            return;
        }
        if(i>j) return;
        sb.push_back(i);
        solve(i+1,j,k,sb,cnt+1);
        sb.pop_back();
        solve(i+1,j,k,sb,cnt);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> sb;
        solve(1,n,k,sb,0);
        return ans;
    }
};