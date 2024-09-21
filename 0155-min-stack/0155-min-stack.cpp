class MinStack {
public:
   stack<long long> st;
    long long mini;
    
    MinStack() {
        mini = LLONG_MAX; // Initialize with the maximum value of long long
    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if(val >= mini) {
                st.push(val);
            } else {
                //2 CONVERTS AS LONG LONG TYPR HERE
                st.push(2LL * val - mini); // Use 2LL to ensure the calculation is done in long long
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) {
            mini = 2LL * mini - x; // Ensure the calculation is done in long long
        }
    }
    
    int top() {
        if(st.top() >= mini) return st.top();
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */