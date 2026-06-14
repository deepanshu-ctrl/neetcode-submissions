class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(auto x:emails){
            int i=0;
            string local="";
            while(i<x.length() && x[i]!='@' && x[i]!='+'){
                if(x[i]!='.') local+=x[i];
                i++;
            }
            while(i<x.length() && x[i]!='@') i++;
            string domain=x.substr(i+1);
            st.insert(local+'@'+domain);
        }
        return st.size();
    }
};