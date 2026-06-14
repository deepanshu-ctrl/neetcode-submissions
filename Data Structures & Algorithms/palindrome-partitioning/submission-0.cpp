class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string> sb;
        solve(sb,s,0,0);
        return ans;
    }
    void solve(vector<string> &sb,string &s,int j,int i){
        if(i>=s.size()){
            if(i==j) ans.push_back(sb);
            return;
        }
        if (pal(s,j,i)){
            sb.push_back(s.substr(j,i-j+1));
            solve(sb,s,i+1,i+1);
            sb.pop_back();
        }
        solve(sb,s,j,i+1);
    }
    bool pal(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;r--;
        }
        return true;
    }
};
