class Solution {
public:
    int m,n;
    vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1}};
    void solve(int i,int j,vector<vector<int>>& h,vector<vector<int>> &vis){
        if(i<0||i>=m||j<0||j>=n||vis[i][j]) return;
        vis[i][j]=1;
        for(auto x:d){
            int ni=i+x[0];
            int nj=j+x[1];
            if(ni<0||ni>=m||nj<0||nj>=n) continue;
            if(vis[ni][nj]) continue;
            if(h[ni][nj]<h[i][j]) continue;
            // vis[ni][nj]=1;
            solve(ni,nj,h,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m=h.size();
        n=h[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pac(m,vector<int>(n,0));
        vector<vector<int>> atl(m,vector<int>(n,0));
        for(int i=0;i<n;i++) solve(0,i,h,pac);
        for(int i=0;i<m;i++) solve(i,0,h,pac);
        for(int i=0;i<n;i++) solve(m-1,i,h,atl);
        for(int i=0;i<m;i++) solve(i,n-1,h,atl);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
