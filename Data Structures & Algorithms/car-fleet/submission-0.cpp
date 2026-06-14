class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int,int>> pair;
        for(int i=0;i<p.size();i++){
            pair.push_back({p[i],s[i]});
        }
        sort(pair.rbegin(),pair.rend());
        vector<double>st;
        for(auto x:pair){
            st.push_back((double)(target-x.first)/x.second);
            if(st.size()>=2 && st.back()<=st[st.size()-2]) st.pop_back();
        }
        return st.size();
    }
};
