class Solution {
public:
    bool isAnagram(string s, string t) {
        // return false if both the strings are not of same size
        if (s.size() != t.size())
            return false;
        
        std::unordered_map<char, int> str_map_1, str_map_2;

        for (size_t i = 0; i < s.size(); i++) {
            str_map_1[s[i]] += 1;
            str_map_2[t[i]] += 1;
        }

        if (str_map_1 == str_map_2)
            return true;
        
        return false;

    }
};
