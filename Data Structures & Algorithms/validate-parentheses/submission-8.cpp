class Solution {
public:
    bool isValid(string s) {
        // try with stack and no hashmap
        // possible
        std::vector<char> stk;

        for (char c : s)
        {
            // iterate through each char
            if (c == '}' && !stk.empty())
            {
                char ch = stk.back();
                if(stk.empty() || ch != '{')
                {
                    return false;
                }
                stk.pop_back();

            } else if (c == ']' && !stk.empty()){
                char ch = stk.back();
                if(stk.empty() || ch != '[')
                {
                    cout << "This ret";
                    return false;
                }
                stk.pop_back();
            } else if ( c == ')' && !stk.empty()) {
                char ch = stk.back();
                if(stk.empty() || ch != '(')
                {
                    return false;
                }
                stk.pop_back();
            } else {
                cout << "push success\n";
                stk.push_back(c);
            }
        }

        if(stk.empty())
        {
            return true;
        }

        
            return false;
    }
};
