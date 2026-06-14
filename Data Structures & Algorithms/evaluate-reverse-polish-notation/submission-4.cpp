class Solution {
public:
    int evalRPN(vector<string>& tk) {
        stack<int> st;
        for(auto x:tk){
            if(x=="+"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(a+b);
            }
            else if(x=="-"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b-a);
            }
            else if(x=="*"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(a*b);
            }
            else if(x=="/"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b/a);
            }
            else st.push(stoi(x));
        }
        return st.top();
    }
};
