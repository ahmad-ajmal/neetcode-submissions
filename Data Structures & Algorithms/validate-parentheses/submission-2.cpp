class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char single : s)
        {
            if (single == '[' || single == '{' || single == '(')
            {
                brackets.push(single);
                continue;
            }
            if (brackets.size() <= 0)
            {
                return false;
            }
            if(single == ']' && brackets.top() == '[')
            {
                brackets.pop();
                continue;
            }
            if(single == '}' && brackets.top() == '{')
            {
                brackets.pop();
                continue;
            }
            if(single == ')' && brackets.top() == '(')
            {
                brackets.pop();
                continue;
            }
            return false;
        }
        if(brackets.size() == 0) return true;
        return false;
    }
};
