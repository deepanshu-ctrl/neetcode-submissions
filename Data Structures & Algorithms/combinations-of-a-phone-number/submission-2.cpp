class Solution {
public:
    vector<string> ans={""};
    vector<string> dict={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // void solve(string dig,int i,string sb){
    //     if(sb.size()==dig.size()){
    //         ans.push_back(sb);
    //         return;
    //     }
    //     string ch=dict[dig[i]-'0'];
    //     for(char x:ch){
    //         solve(dig,i+1,sb+x);
    //     }

    // }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        // solve(digits,0,"");
        for(auto x:digits){
            vector<string>temp;
            for(auto s:ans){
                for(auto c:dict[x-'0']){
                    temp.push_back(s+c);
                }
            }
            ans=temp;
        }
        return ans;
    }
};
