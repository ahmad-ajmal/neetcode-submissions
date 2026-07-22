class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string& val : strs)
        {
            int str_length = val.size();
            encoded_string.append("" + to_string(str_length) + "#" + val);
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        cout<<s<<endl;
        int i = 0;
        while (i < s.size())
        {
            int hash_pos = s.find('#', i);
            int length = stoi(s.substr(i, hash_pos-i));

            decoded_strings.push_back(s.substr(hash_pos + 1, length));

            cout<<endl;

            i = hash_pos + 1 + length;
        }

        return decoded_strings;
    }
};
