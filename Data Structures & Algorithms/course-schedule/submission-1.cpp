class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> ind(n,0);
        for(auto x:adj){
            for(auto i:x){
                ind[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        // vector<int> vis(n,0);
        int cnt=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            cnt++;
            for(auto x:adj[f]){
                    ind[x]--;
                    if(ind[x]==0){
                        q.push(x);
                    }
            }
        }
        return n==cnt;
    }
};
