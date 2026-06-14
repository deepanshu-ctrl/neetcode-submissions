class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& iv) {
        if(iv.size()==0) return 0;
        sort(iv.begin(),iv.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
    int cnt=0;
    int e=iv[0][1];
    for(int i=1;i<iv.size();i++){
        if(iv[i][0]<e) cnt++;
        else e=iv[i][1];
        }
        return cnt;
    }
};
