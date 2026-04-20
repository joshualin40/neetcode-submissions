class MinStack {
    stack<int> lowest;
    stack<int> s;
public:
    MinStack() {
        lowest.push(INT_MAX);
    }
    
    void push(int val) {
        if (val <= lowest.top())
            lowest.push(val);
        s.push(val);
    }
    
    void pop() {
        if (s.top() == lowest.top()) lowest.pop();
        s.pop();
        // what if there are two occurences of lastmin
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return lowest.top();
    }
    // obviously could search through entire stack but then that would be O(n)
};
