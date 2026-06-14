class Solution {
public:
    int calPoints(vector<string>& op) {
        int ans=0;
        stack<int> st;
        int a,b;
        for(auto x:op){
            if(x=="+"){
                a=st.top();
                st.pop();
                b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(x=="D"){
                a=st.top();
                st.push(2*a);
            }
            else if(x=="C"){
                st.pop();
            }
            else{
                st.push(stoi(x));
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};