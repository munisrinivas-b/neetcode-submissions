class Solution {
    // In brute force you can try with Tree appraoch
public:
    int climbStairs(int n) {
        int rec_call_count  = 0; // this var stores the number of times the function being called and that is our result
        if(n <= 2)
            return n; // Base case
        else {
            // rec_call_count++;
            rec_call_count = climbStairs(n-1)+climbStairs(n-2);
        }

        return rec_call_count;        
    }
};
