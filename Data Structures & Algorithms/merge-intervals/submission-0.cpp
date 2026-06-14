class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        sort(iv.begin(),iv.end());
        vector<vector<int>> op;
        op.push_back(iv[0]);
        for(auto x:iv){
            int s=x[0];
            int e=x[1];
            int le=op.back()[1];
            if(s<=le){
                op.back()[1]=max(le,e);
            }
            else{
                op.push_back({s,e});
            }
        }
        return op;
    }
};
