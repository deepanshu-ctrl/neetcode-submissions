class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        vector<int> ans;
        for(auto x:as){
            while(!st.empty() && x<0 && st.top()>0){
                if(abs(x)>abs(st.top())){
                    st.pop();
                    continue;
                }
                else if(abs(st.top()==abs(x))){
                    st.pop();
                    x=0;
                }
                else{
                    x=0;
                }
                break;
            }
            if(x) st.push(x);
            // if(st.empty()){
            //     st.push(x);
            //     continue;
            // }
            // if(abs(x)>abs(st.top()) && x*st.top()<0){
            //     st.pop();
            //     st.push(x);
            // }
            // else if(abs(st.top())==abs(x) && st.top()*x<0) st.pop();
            // else if(abs(x)<abs(st.top()) && x*st.top()<0) continue;
            // else{
            //     st.push(x);
            // }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};