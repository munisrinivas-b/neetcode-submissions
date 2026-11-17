class Node {
public:
    int val;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int value, Node* nxt = nullptr, Node* prv = nullptr)
        : val(value), next(nxt), prev(prv) {}
};

class Deque {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    Deque() {
      cout << "Deque Init success\n";
    }

    bool isEmpty() {
        cout << "isEmpty\n";
        if(head == nullptr)
            return true;
        
        return false;
    }

    void append(int value) {
        cout << "append\n";
        if (head == nullptr)
        {
            head = new Node(value); // init value, prev and next points to null
            tail = head;
        } else {
            // there already exists some elements reach the end
            tail->next = new Node(value, nullptr, tail); // form the link
            tail = tail->next; // update the tail pointer
        }
        
    }

    void appendleft(int value) {
        cout << "append left\n";

        if (head == nullptr)
        {
            head = new Node(value); // init value, prev and next points to null
            tail = head;
        } else {
            // there already exists some elements reach the beginning
            head->prev = new Node(value, head, nullptr);
            head = head->prev; // update the head pointer
        }
        
    }

    int pop() {
        cout << "pop\n";
        if (head == nullptr)
        {
            // empty queue
            return -1;
        } else {
            int val = tail->val;
            if (head != tail){
                tail = tail->prev; // move tail to onestep back
                tail->next = nullptr; // make the next field to null to make it the last element
            } else if(head == tail) {
                head = nullptr;
                tail = nullptr;

            }
            return val;
        }
    }

    int popleft() {
        cout << "pop left\n";
        if (head == nullptr)
        {
            // empty queue
            return -1;
        } else {
            int val = head->val;
            if (head != tail) {
                head = head->next; // move tail to onestep back
                head->prev = nullptr; // make the next field to null to make it the last element
            } else if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            

            return val;

        }


    }
};
