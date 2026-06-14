class Solution {
public:
    void solve(vector<vector<int>> &adj,int i, vector<int> &vis){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                solve(adj,x,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                solve(adj,i,vis);
            }
        }
        return ans;
    }
};
