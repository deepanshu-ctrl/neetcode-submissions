class Solution {
public:
    int solve(int i){
        int cnt=0;
        while(i){
            if(i&1) cnt++;
            i>>=1;
        }return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0;i<=n;i++){
            int ans=solve(i);
            v.push_back(ans);
        }
        return v;
    }
};
