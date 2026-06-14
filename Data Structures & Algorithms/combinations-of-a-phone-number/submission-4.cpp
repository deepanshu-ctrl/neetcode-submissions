class Solution {
public:
    vector<string> ans;
    vector<string> dict={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string &dig,int i,string sb){
        if(sb.size()==dig.size()){
            ans.push_back(sb); return;
        }
        string ch=dict[dig[i]-'0'];
        for(auto x:ch){
            sb.push_back(x);
            solve(dig,i+1,sb);
            sb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        solve(digits,0,"");
        return ans;
    }
};
