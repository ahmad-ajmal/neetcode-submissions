class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int smallest_num = INT_MIN;
        int last_longest_sequence = 0;
        int current_longest_sequence = 0;
        for(int n : nums)
        {
            if(n == smallest_num + 1)
            {
                current_longest_sequence += 1;
                smallest_num = n;
                
                if(current_longest_sequence > last_longest_sequence)
                {
                    last_longest_sequence = current_longest_sequence;
                }
                continue;
            }
            if(n != smallest_num + 1 && n != smallest_num) 
            {
                smallest_num = n;
                current_longest_sequence = 0;
            }
        }

        return last_longest_sequence + 1;
    }
};
