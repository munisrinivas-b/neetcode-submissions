class Deque {
public:
    std::vector<int> dq;
    Deque() {
        dq.clear();
    }

    bool isEmpty() {
        return  dq.empty();
    }

    void append(int value) {
        dq.push_back(value);
    }

    void appendleft(int value) {
        dq.insert(dq.begin(), value);
    }

    int pop() {
        if(dq.empty())
            return -1;

        int val = dq.back();
        dq.pop_back();
        return val;
    }

    int popleft() {
        if(dq.empty())
            return -1;

        int val = dq.front();
        dq.erase(dq.begin());
        return val;
    }
};
