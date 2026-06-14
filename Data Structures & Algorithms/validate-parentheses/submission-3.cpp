class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto x:s){
            if(x=='('||x=='['||x=='{') st.push(x);
            else{
                if(st.empty()) return false;
                if((st.top()=='('&& x==')') ||
                (st.top()=='{'&& x=='}') ||
                (st.top()=='['&& x==']') ) st.pop();
                else return false;
            }
        }
    return st.empty();
    }
};
