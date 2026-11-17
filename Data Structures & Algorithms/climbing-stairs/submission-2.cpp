class Solution {
public:
    int climbStairs(int n) {
        int total_ways = 0;
        int curr_val = 0;
        helper(n, total_ways, curr_val);
        return total_ways;
    }

    void helper(int& n, int& total_ways, int curr_val) {
        if(curr_val == n)
            total_ways++;
        else if(curr_val > n)
            return;

        helper(n, total_ways, curr_val+1);
        helper(n, total_ways, curr_val+2);
    }
};
