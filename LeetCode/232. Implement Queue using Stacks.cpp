class MyQueue {
public:
    vector<int> _queue;
    
    MyQueue() {
        _queue = {};
    }
    
    void push(int x) {
        _queue.push_back(x);
    }
    
    int pop() {
        int val = _queue[0];
        _queue.erase(_queue.begin());
        return val;
    }
    
    int peek() {
        return _queue[0];
    }
    
    bool empty() {
        return _queue.size() == 0;    
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */