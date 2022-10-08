class MinStack {
public:
    stack<pair<int,int> > s;
    MinStack() {
        
    }
    
    void push(int val) {
        int mn;
        if(s.empty())
            mn=val;
        else
            mn=s.top().second<val?s.top().second:val;
        s.push({val,mn});
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
