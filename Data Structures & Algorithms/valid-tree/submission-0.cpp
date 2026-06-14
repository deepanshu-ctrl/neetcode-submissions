class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        queue<pair<int,int>>q;
        int ans=0;
        q.push({0,-1});
        vis[0]=1;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int node=x.first;
            int p=x.second;
            ans++;
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(i!=p) return false;
            }
        }
        return ans==n;
    }
};
