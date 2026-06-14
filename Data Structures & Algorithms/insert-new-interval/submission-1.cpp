class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& ni) {
        vector<vector<int>> ans;
        int n=iv.size();
        int i=0;
        while(i<n && iv[i][1]<ni[0]){
            ans.push_back(iv[i]); i++;
        }
        while(i<n && ni[1]>=iv[i][0]){
            ni[0]=min(iv[i][0],ni[0]);
            ni[1]=max(ni[1],iv[i][1]);
            i++;
        }
        ans.push_back(ni);
        while(i<n){
            ans.push_back(iv[i++]); 
        }
        return ans;
    }
};
