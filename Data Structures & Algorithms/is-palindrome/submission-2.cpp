class Solution {
public:
    bool isPalindrome(string s) {
        int starting_index = 0;
        int last_index = s.size() - 1;

        while(starting_index < last_index)
        {
            // Skip non-alphanumeric on the left
            while (starting_index < last_index && !isalnum(s[starting_index])) {
                starting_index++;
            }
            // Skip non-alphanumeric on the right
            while (starting_index < last_index && !isalnum(s[last_index])) {
                last_index--;
            }

            if (tolower(s[starting_index]) != tolower(s[last_index])) {
                return false;
            }

            starting_index++;
            last_index--;
        }

        return true;
    }
};
