class Solution {
public:

    int climbStairs(int n) {
        int first=1;
        int second=2;
        while(n>1)
        {
            int temp=first;
            first=second;
            second=temp+second;
            n--;
        }
        cout<<first<<" "<<second<<endl;
        return first;
    }
};
