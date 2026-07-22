class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;                 // base case: empty → not found

        int middle = n / 2;

        if (nums[middle] == target) {
            return middle;                     // found → index is middle
        }
        else if (target > nums[middle]) {
            // search the right half: nums[middle+1 .. end]
            vector<int> right(nums.begin() + middle + 1, nums.end());
            int r = search(right, target);
            return (r == -1) ? -1 : middle + 1 + r;   // add back the offset
        }
        else {
            // search the left half: nums[0 .. middle)
            vector<int> left(nums.begin(), nums.begin() + middle);
            return search(left, target);       // offset is 0, return as-is
        }
    }
};
