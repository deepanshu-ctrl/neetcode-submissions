class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sz;
        string ans="";
        for(auto s:strs){
            sz.push_back(s.size());
        }
        for(int c:sz) ans+=to_string(c)+',';
        ans+='#';
        for(auto x: strs) ans+=x;
        return ans;
    }

    vector<string> decode(string s) {
        if(s.empty()) return{};
        vector<int> sz;
        vector<string> ans;
        int i=0;
        while(s[i]!='#'){
            string c="";
            while(s[i]!=','){
                c+=s[i]; i++;
            }
            sz.push_back(stoi(c));
            i++;
        }
        i++;
        for(auto x:sz){
            ans.push_back(s.substr(i,x));
            i+=x;
        }
        return ans;
    }
};
