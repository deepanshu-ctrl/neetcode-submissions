class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &cand,int i,vector<int> &temp,int tar,int s){
        if(s==tar){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<cand.size();j++){
            if(j>i && cand[j]==cand[j-1]) continue;
            if(s+cand[j]>tar) break;
            temp.push_back(cand[j]);
            solve(cand,j+1,temp,tar,s+cand[j]);
            temp.pop_back();
        }
        // if(i==cand.size()||s>tar) return;
        // temp.push_back(cand[i]);
        // solve(cand,i+1,temp,tar,s+cand[i]);
        // temp.pop_back();
        // while(i+1<cand.size() && cand[i]==cand[i+1]) i++;
        // solve(cand,i+1,temp,tar,s);
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<int> temp;
        sort(cand.begin(),cand.end());
        solve(cand,0,temp,target,0);
        return ans;
    }
};
