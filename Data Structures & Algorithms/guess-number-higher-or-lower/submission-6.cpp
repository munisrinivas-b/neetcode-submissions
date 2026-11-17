/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // run a binary search from 1 to n,
        // helper function is guess(n)

        // Note that in this problem, we will always 
        // find the requested value, no need of return -1

        int left = 1;
        int right = n;

        while(left <= right) {
            // safe way to avoid overflow while computing the mid
            int mid = left + (right-left)/2;
            int ret_val = guess(mid);

            if(ret_val == 0) {
                // guess matched the pick, return the ans
                return mid;
            } else if(ret_val == -1) {
                // guess is higher than pick
                right = mid-1;
            } else if(ret_val == 1) {
                left = mid + 1;
            }

        }
        
    }
};