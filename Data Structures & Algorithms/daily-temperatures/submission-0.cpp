class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ans(t.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i<t.size();i++){
            int x=t[i];
            while(!st.empty() && x>st.top().first){
                auto p=st.top();
                st.pop();
                ans[p.second]=i-p.second;
            }
            st.push({x,i});
        }
        return ans;
    }
};
