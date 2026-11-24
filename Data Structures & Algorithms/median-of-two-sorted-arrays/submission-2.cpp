class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Swap the arrays such that A has the smallest size compared to B
        vector<int> A(nums1);
        vector<int> B(nums2);

        if (A.size() > B.size())
            std::swap(A,B); // A is the smallest array now

        // Pointers to the left and right extremes of A, for binary search
        int l = 0;
        int r = A.size(); // These are for partitions, for n-size array, we'll have n+1 partitions

        int total_size = A.size() + B.size();
        int half_size = (total_size + 1)/ 2; // half_size also shows the split location, hence +1 us needed, needs int here as we are indexing 

        // I am confusing mostly with this i, j as indexes rather than taking it as positions
        // i + j = half_size
        // Maintain the pointers to the splits
        int i = (l + r) / 2; // Number of elements, taken from the A array, not the index
        int j = (half_size - i); // Number of elements, taken from the B array, not the index

        while (l <= r) {
            int A_left = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == A.size()) ? INT_MAX : A[i];
            int B_left = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == B.size()) ? INT_MAX : B[j];

            // condition satisified
            if ((A_left <= B_right) && (B_left <= A_right)) {
                //Median found
                if (total_size % 2 == 0) {
                    //even array, take the avg of middle elements
                    return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
                } else {
                    // odd array, pick the middle element, easy
                    return (max(A_left, B_left));
                }
            } else if (A_right < B_left) {
                l = i + 1;
            } else if (A_left > B_right) {
                r = i - 1;
            }
            i = (l + r) / 2;
            j = half_size - i;
        }

        return 0.0;
    }
};
