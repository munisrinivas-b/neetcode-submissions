class Solution {
public:
    bool isValid(string s) {
        
        std::vector<char> stk;
        stk.clear();

        // Map to check if the closing parameter has encountered
        std::unordered_map<char, char> matches = {
            {'}' , '{'},
            {']' , '['},
            {')' , '('}
        };

        // The number of elements has to be even, else return false
        if (s.size() % 2 != 0)
            return false;

        // Store the characters in the stack
        for(char &c : s) {
            
            // for open types, store them in the stack
            if ((c == '{') || (c == '[') || (c == '(')) {
                stk.push_back(c);
            }
            // for the close brace types, check with the last character in the stack
            else if ((c == '}') || (c == ']') || (c == ')')) {
                if (stk.size() != 0) {
                    if (matches[c] != stk.back()) {
                        return false;
                    } else{
                        stk.pop_back();
                    }
                } else {
                    return false;
                }
            }
    
        }

        if (stk.size() != 0)
            return false;
        else
            return true;

    }
};
