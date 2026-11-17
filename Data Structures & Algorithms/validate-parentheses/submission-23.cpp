class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> brace_match;

        brace_match['}'] = '{';
        brace_match[')'] = '(';
        brace_match[']'] = '[';

        std::vector<char> stk;

        int str_len = s.length();

        if((str_len == 0) || (str_len % 2 != 0))
            return false;

        for(int i = 0; i < str_len; i++) {
            // If the closing brace occurs then check for the top
            // of the stack and try to find its matching

            if(brace_match.count(s[i]) == 0) {
                // opening brace
                // store it in the stack
                stk.push_back(s[i]);
            } else {
                // close brace occured
                char matching_element = brace_match[s[i]];

                if(stk.empty())
                    return false;

                if(matching_element == stk.back()) {
                    //match found
                    stk.pop_back();
                } else {
                    return false;
                }
            }
        }

        if(stk.empty())
            return true;
        else
            return false;

    }
};
