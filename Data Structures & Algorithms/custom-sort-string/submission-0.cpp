class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mpp;
        for(auto x:s) mpp[x]++;
        string ans="";
        for(auto x:order){
            if(mpp.find(x)!=mpp.end()){
                int n=mpp[x];
                while(n){
                    ans+=x;
                    n--;
                }
                mpp.erase(x);
            }
        }
        for(auto x:s){
            if(mpp.find(x)!=mpp.end()) ans+=x;
        }
        return ans;
    }
};