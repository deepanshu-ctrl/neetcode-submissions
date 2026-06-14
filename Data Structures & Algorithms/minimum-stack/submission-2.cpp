class MinStack {
public:
    stack<long> st;
    long  min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min=val;
        }
        else{
        st.push(val-min); if(val<min) min=val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long p= st.top();
        st.pop();
        if(p<0) min=min-p;
    }
    
    int top() {
        long t=st.top();
        return (t>0)?(t+min):(int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
