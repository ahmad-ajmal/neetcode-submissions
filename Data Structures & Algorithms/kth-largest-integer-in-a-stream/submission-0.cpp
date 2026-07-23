class KthLargest {
    vector<int> nums;
    int nth_largest = 0;

public:
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->nth_largest = k;
    }
    
    int add(int val) {
        this->nums.push_back(val);
        sort(this->nums.begin(), this->nums.end());
        print();
        return this->nums[this->nums.size() - this->nth_largest];
    }

    void print()
    {
        for(int i : this->nums)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
};
