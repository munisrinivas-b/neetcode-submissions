class Solution {
public:
    int climbStairs(int n) {

        if(n <= 1) {
            return 1;
        }

        int ways_cnt = climbStairs(n-1) + climbStairs(n-2);

        return ways_cnt; 
    }
};
