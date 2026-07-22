class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i<nums.size(); i++)
        {
            int looking_for = target - nums[i]; // remainder to look for
            if(seen.contains(looking_for))
            {
                return {seen[looking_for], i};
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};
