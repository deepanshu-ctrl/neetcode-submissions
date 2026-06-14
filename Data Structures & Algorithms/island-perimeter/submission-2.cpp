class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int r=g.size(),c=g[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=true;
                    int p=0;
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        for(auto xi:d){
                            int nx=x+xi[0],ny=y+xi[1];
                            if(nx<0||ny<0||nx>=r||ny>=c||g[nx][ny]==0) p++;
                            else if(!vis[nx][ny]){
                                vis[nx][ny]=true;
                                q.push({nx,ny});
                            }
                        }
                    }
                    return p;
                }
            }
        }
        return 0;
    }
};