class Solution {
public:
    int maxDepth(string s) {
        std::vector<char> stk;
        int max_num = 0;

        int str_len = s.size();

        for(int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                stk.push_back(s[i]);
            } else if (s[i] == ')') {
                stk.pop_back();
            }

            if(stk.size() > max_num)
                max_num = stk.size();
        }

        return max_num;
        
    }
};