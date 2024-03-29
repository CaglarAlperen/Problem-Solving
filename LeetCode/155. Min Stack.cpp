class MinStack {
public:
    stack<pair<int,int>> s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if (!s.empty() && s.top().second < val)
        {
            s.push(make_pair(val,s.top().second));
        }
        else 
        {
            s.push(make_pair(val, val));
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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