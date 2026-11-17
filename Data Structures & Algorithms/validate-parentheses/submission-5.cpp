class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mappings = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'},
        };

        int str_size = s.size();

        if ((str_size == 0) || (str_size%2 != 0))
        {
            // cout<< "this one";
            return false;
        }

        vector<char> stk; // stack that stores the opening braces
        for(char c : s)
        {
            // std::cout << "char : " << c << std::endl;
            // iterate through each character in the string
            if ((mappings.find(c) != mappings.end()) && (!stk.empty()))
            {
                auto itr = mappings.find(c);
                char match_char = stk.back();
                stk.pop_back();

                if (itr->second != match_char)
                {
                    // cout << "Ths 2\n";
                    return false;
                }
            }
            else
            {
                // add it to the stack
                // cout << "stack\n";
                stk.push_back(c);
            }
        }

        if(stk.empty())
            return true;

        return false;
    }
};
