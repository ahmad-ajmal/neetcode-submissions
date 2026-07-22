class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums)
        {
            freq[x]++;
        }

        vector<pair<int, int>> val;
        for(auto&[value, count] : freq)
        {
            val.push_back({count, value});
        }

        sort(val.begin(), val.end(), greater<>());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(val[i].second);
        }

        return result;
    }
};
