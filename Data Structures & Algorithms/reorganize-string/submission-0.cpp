class Solution {
public:
    int solve(vector<int> &f){
        int mid=0;
        for(int i=1;i<f.size();i++){
            if(f[i]>f[mid]) mid=i;
        }
        return mid;
    }
    string reorganizeString(string s) {
        vector<int> f(26,0);
        for(auto x:s) f[x-'a']++;
        int mf=*max_element(f.begin(),f.end());
        if(mf>(s.size()+1)/2) return "";
        string ans;
        while(ans.size()<s.size()){
            int midx=solve(f);
            char maxc='a'+midx;
            ans+=maxc;
            f[midx]--;
            if(f[midx]==0) continue;
            int tmp=f[midx];
            f[midx]=INT_MIN;
            int nmx=solve(f);
            char nxch='a'+nmx;
            ans+=nxch;
            f[midx]=tmp;
            f[nmx]--;
        }
        return ans;
    }
};