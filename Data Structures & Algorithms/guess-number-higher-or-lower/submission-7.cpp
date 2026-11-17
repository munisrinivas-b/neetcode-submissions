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

        int res = guessHelper(1, n);

        return res;
    }

    int guessHelper(int s, int e) {
        // range = 1 to n

        // pick the middle one
        int my_guess = s + (e-s)/2;
        int ret_val;
        if(guess(my_guess) == 0) {
            // guess matched the picked
            ret_val = my_guess;
        } else if(guess(my_guess) == -1) {
            // guess > target
            ret_val = guessHelper(s, my_guess-1);
        }else if(guess(my_guess) == 1) {
            // guess > target
            ret_val = guessHelper(my_guess+1, e);
        }

        return ret_val;

    }
};