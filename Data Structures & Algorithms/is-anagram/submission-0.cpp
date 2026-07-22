class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if(s_size != t_size)
        {
            return false;
        }

        unordered_map<char, int> found_char_s;
        for(int i = 0; i<s_size; i++)
        {
            found_char_s[s[i]] = found_char_s[s[i]] + 1;
        }
        unordered_map<char, int> found_char_t;
        for(int i = 0; i<t_size; i++)
        {
            found_char_t[t[i]] = found_char_t[t[i]] + 1;
        }

        for(int i = 0; i < s_size; i++)
        {
            if(found_char_s[s[i]] != found_char_t[s[i]])
            {
                return false;
            }
        }

        return true;
    }
};
