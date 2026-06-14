class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inc(n+1,0);
        for(auto t:trust){
            inc[t[0]]--;
            inc[t[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(inc[i]==n-1) return i;
        }
        // for(int i=1;i<=n;i++){
        //     if(out[i]==0 && inc[i]==n-1) return i;
        // }
        return -1;
    }
};