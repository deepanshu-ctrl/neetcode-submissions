class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string s;
        for(char x:path+"/"){
            if(x=='/'){
                if(s==".."){
                    if(!st.empty()) st.pop_back();
                }
                else if(!s.empty() && s!=".") st.push_back(s);
            s.clear();
            }
            else{
                s+=x;
            }
        }
        string ans="/";
        for(int i=0;i<st.size();i++){
            if(i>0) ans+="/";
            ans+=st[i];
        }
        return ans;
    }
};