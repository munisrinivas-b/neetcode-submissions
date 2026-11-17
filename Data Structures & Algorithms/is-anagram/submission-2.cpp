class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hmap, hmap_t;
        bool res = true;

        for(int i = 0; i < s.size(); i++) {
            if(hmap.count(s[i]) != 0) {
                // character already exists
                hmap[s[i]]++;
            } else {
                hmap[s[i]] = 1;
            }
        }

        for(int i = 0; i < t.size(); i++) {
            if(hmap_t.count(t[i]) != 0) {
                // character already exists
                hmap_t[t[i]]++;
            } else {
                hmap_t[t[i]] = 1;
            }
        }

        if(hmap.size() > hmap_t.size()) {
            for(auto itr = hmap.begin(); itr != hmap.end(); itr++) {
            // find the character in the hmap_t and check
            // whether it's value matches with the hmap key's value

            // a. check whetehr the same key exists in both
            // hmap & hmap_t
                if((hmap_t.count(itr->first) == 0) || (hmap_t[itr->first] != hmap[itr->first])) {
                    res = false;
                    break;
                }
            }
        } else {
             for(auto itr = hmap_t.begin(); itr != hmap_t.end(); itr++) {
            // find the character in the hmap_t and check
            // whether it's value matches with the hmap key's value

            // a. check whetehr the same key exists in both
            // hmap & hmap_t
                if((hmap.count(itr->first) == 0) || (hmap_t[itr->first] != hmap[itr->first])) {
                    res = false;
                    break;
                }
             }

        }
        

        return res;
    }
};
