class KthLargest {
    // use the mineHeap property here
    // If we trim the given vector to the K-sized minHeap, the 
    // root always contain the least element wihtin the k-top most elements
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap_;
    int k_;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k_ = k;

        // add the elements from the nums to the heap
        for(int num : nums) {
            minHeap_.push(num);

            if(minHeap_.size() > k) {
                // remove the top element (i.e, min element, we need to store only the TOP K elements) 
                minHeap_.pop();
            }
        }
    }
    
    int add(int val) {
        // cout << "Adding : " << val << endl;
        // cout << "prev state : " << endl;
        // for (int ele : minHeap_)
        //     cout << ele << " , ";
        // cout << "before push : " << minHeap_.size() << endl;
        minHeap_.push(val);

        // cout << "After state : " << endl;
        // for (int ele : minHeap_)
        //     cout << ele << " , ";
        
        // only pop if size exceeds k
        // cout << "after push : " << minHeap_.size() << endl;
        if(minHeap_.size() > k_)
            minHeap_.pop();
        // cout << "after pop : " << minHeap_.size() << endl;
        // cout << "Final state : " << endl;
        // for (int ele : minHeap_)
        //     cout << ele << " , ";

        return minHeap_.top();
    }
};
