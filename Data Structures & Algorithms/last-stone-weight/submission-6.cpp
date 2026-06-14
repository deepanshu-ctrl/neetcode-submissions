class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ms=0;
        for(auto x:stones){
            ms=max(ms,x);
        }
        vector<int>b(ms+1,0);
        for(int x:stones){
            b[x]++;
        }
        int f=ms,s=ms;
        while(f>0){
            if(b[f]%2==0){
                f--; continue;
            }
            int j=min(f-1,s);
            while(j>0 && b[j]==0) j--;
            if(j==0) return f;
            s=j;
            b[f]--;
            b[s]--;
            b[f-s]++;
            f=max(f-s,s);
        }
    return f;
    }
};
