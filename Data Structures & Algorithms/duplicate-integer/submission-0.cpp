class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() <= 0)
        {
            return false;
        }

        // If not 0
        unordered_map<int, int> found;
        for (int i=0; i<nums.size(); i++)
        {
            if(found.count(nums[i]))
            {
                // key exists
                return true;
            }

            found[nums[i]] = nums[i];
        }

        return false;
    }
};