class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);   // start all 1s

        // Pass 1: fill output[i] with the product of everything to its LEFT
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            output[i] = prefix;     // product of elements before i
            prefix *= nums[i];      // include nums[i] for the next position
        }

        // Pass 2: multiply in the product of everything to the RIGHT
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= suffix;    // multiply by product of elements after i
            suffix *= nums[i];      // include nums[i] for the next position
        }

        return output;
    }
};
