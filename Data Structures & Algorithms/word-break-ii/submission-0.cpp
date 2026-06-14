class Solution {
public:
    unordered_set<string> w;
    vector<string> ans;
    void solve(string &s,int i,vector<string> &c){
        if(i==s.size()){
            ans.push_back(join(c));
            return;
        }
        for(int j=i;j<s.size();j++){
            string st=s.substr(i,j-i+1);
            if(w.count(st)){
                c.push_back(st);
                solve(s,j+1,c);
                c.pop_back();
            }
        }
    }
    string join(vector<string> &word){
        string rs=word[0];
        for(int i=1;i<word.size();i++)
            rs+=" "+word[i];
        return rs;
    }
    vector<string> wordBreak(string s, vector<string>& wd) {
        w=unordered_set<string>(wd.begin(),wd.end());
        vector<string>c;
        solve(s,0,c);
        return ans;
    }
};