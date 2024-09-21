class MinStack {
public:
    long long arr[10000];
    int topp;
    long long mini;
    MinStack() {
        mini = LLONG_MAX;
        topp = -1;
    }
    
    void push(int val) {
        if (topp == -1) {
            mini = val;
            arr[++topp] = val;
        } else if (val < mini) {
            arr[++topp] = 2LL * val - mini;
            mini = val;
        } else {
            arr[++topp] = val;
        }
    }
    
    void pop() {
        if (topp == -1) return;
        long long curr = arr[topp--];
        if (curr < mini) {
            mini = 2 * mini - curr;
        }
    }
    
    int top() {
        if (topp == -1) return -1;
        long long curr = arr[topp];
        return (curr < mini) ? mini : curr;
    }
    
    int getMin() {
        return (topp == -1) ? -1 : mini;
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