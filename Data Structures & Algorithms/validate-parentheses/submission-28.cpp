class Solution {
public:
    bool isValid(string s) {

        if(s.empty() || (s.size()%2 != 0))
            return false;
        
        std::map<char, char> brace_map;

        brace_map[')'] = '(';
        brace_map['}'] = '{';
        brace_map[']'] = '[';

        std::vector<char> inp_stack;

        for(auto s_curr : s) {
            if((s_curr == ')') || (s_curr == '}') || (s_curr == ']')) {
                if(!inp_stack.empty()) {
                    if(inp_stack.back() != brace_map[s_curr]) {
                        return false;
                    } else {
                        inp_stack.pop_back();
                    }
                } else if(inp_stack.empty()) {
                    if((s_curr == ')') || (s_curr == '}') || (s_curr == ']'))
                        return false;
                }
            } else {
                inp_stack.push_back(s_curr);
            }
            
        }

        if(!inp_stack.empty())
            return false;
            
        return true;
    }
};
