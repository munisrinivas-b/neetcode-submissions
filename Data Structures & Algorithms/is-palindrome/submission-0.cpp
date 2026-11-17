class Solution {
public:
    bool is_numeric(char c) {
        return (c >= '0' && c <= '9') || 
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z');
    }
    bool isPalindrome(string s) {
        std::vector<char> first_to_last, last_to_first;

        for(char &c : s) {
            if (is_numeric(c)) {
                char c_new = static_cast<unsigned char>(std::tolower(static_cast<unsigned char>(c)));
                first_to_last.push_back(c_new);
            }
        }

        // Try one pointer to the first and the other to the last 
        // then compare the elements based on the even or odd number
        int n_size = first_to_last.size();
        for(int i = 0; i < n_size/2; i++) {
            // cout << first_to_last[i] << "  , " << first_to_last[n_size - 1 - i] << endl;
            if (first_to_last[i] != first_to_last[n_size - 1 - i])
                return false;
        }

        return true;
        
    }
};
