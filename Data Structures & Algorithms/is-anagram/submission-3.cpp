class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort the strings
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if (s == t)
            return true;
        
        return false;
    }
};
