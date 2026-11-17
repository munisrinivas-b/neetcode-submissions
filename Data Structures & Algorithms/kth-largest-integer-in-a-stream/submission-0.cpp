class KthLargest {
private:
    static bool com_func(int a, int b) {
        return a < b;
    }

    vector<int> nums_;
    int k_;

public:
    KthLargest(int k, vector<int>& nums) {
        nums_ = nums;
        k_ = k;

        // cout << "Object inti : " <<  nums_.size() << endl;
    }
    
    int add(int val) {
        // cout << "before size : " << nums_.size() << endl;
        nums_.push_back(val);
        // cout << "after size : " << nums_.size() << endl;
        std::sort(nums_.begin(), nums_.end(), com_func);
        return nums_[nums_.size()-k_];
    }


};
