class MinStack {
    std::vector<int> stk;
public:
    MinStack() {
        stk.clear();
    }
    
    void push(int val) {
        stk.push_back(val);
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        auto min_ele = std::min_element(stk.begin(), stk.end());

        return *min_ele;
        
    }
};
