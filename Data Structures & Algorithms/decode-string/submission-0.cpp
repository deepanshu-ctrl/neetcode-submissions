class Solution {
public:
    string solve(int &i, string &s){
        string ans;
        int k=0;
        while(i<s.size()){
            char c=s[i];
            if(isdigit(c)){
                k=k*10+(c-'0');
            }
            else if(c=='['){
                i++;
                string sb=solve(i,s);
                while(k-->0) ans+=sb;
                k=0;
            }
            else if(c==']'){
                return ans;
            }
            else ans+=c;
            i++;
        }
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        return solve(i,s);
    }
};