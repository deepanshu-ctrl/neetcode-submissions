class Solution {
public:
    // bool solve(vector<int> &mat,vector<int> &sd,int i){
    //     if(i==mat.size()){
    //         return sd[0]==sd[1] && sd[1]==sd[2] && sd[2]==sd[3];
    //     }
    //     for(int j=0;j<4;j++){
    //         sd[j]+=mat[i];
    //         if(solve(mat,sd,i+1)) return true;
    //         sd[j]-=mat[i];
    //     }
    //     return false;
    // }
    bool solve(vector<int> &mat,vector<int> &sd,int i,int l){
        if(i==mat.size()) return true;
        for(int id=0;id<4;id++){
            if(sd[id]+mat[i]<=l){
                sd[id]+=mat[i];
                if(solve(mat,sd,i+1,l)) return true;
                sd[id]-=mat[i];
            }
            if(sd[id]==0) break;
        }
        return false;
    }
    bool makesquare(vector<int>& mat) {
        int s=accumulate(mat.begin(),mat.end(),0);
        if(s%4!=0) return false;
        int l=s/4;
        vector<int> sd(4,0);
        sort(mat.rbegin(),mat.rend());
        return solve(mat,sd,0,l);
    }
};