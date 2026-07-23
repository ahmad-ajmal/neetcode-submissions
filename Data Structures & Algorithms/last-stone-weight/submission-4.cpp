class Solution {
public:

    pair<int, int> findNextLargest(vector<int> stones, pair<int,int> under)
    {
        int best_index = -1;         // -1 means "none found"
        int largest    = INT_MIN;    // best value so far

        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] <= under.second && i != under.first && stones[i] > largest) {
                largest    = stones[i];
                best_index = i;
            }
        }

        return {best_index, largest};   // {-1, INT_MIN} if nothing is under `under`
    }

    void print(vector<int> stones)
    {
        for(int i : stones)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1)
        {   
            print(stones);
            pair<int, int> largestOne = this->findNextLargest(stones, {-1, INT_MAX});
            pair<int, int> largestSecond = this->findNextLargest(stones, largestOne);
            
            if (largestOne.second == largestSecond.second)
            {
                if(largestOne.first > largestSecond.first)
                {
                    stones.erase(stones.begin() + largestOne.first);
                    stones.erase(stones.begin() + largestSecond.first);
                }
                else
                {
                    stones.erase(stones.begin() + largestSecond.first);
                    stones.erase(stones.begin() + largestOne.first);
                }
                continue;
            }

            if(largestOne.second > largestSecond.second)
            {
                stones[largestOne.first] = largestOne.second - largestSecond.second; 
                stones.erase(stones.begin() + largestSecond.first);
            }
            else
            {
                stones[largestSecond.first] = largestSecond.second - largestOne.second; 
                stones.erase(stones.begin() + largestOne.first);
            }
        }
        print(stones);
        if(stones.size() > 0)
        {
            return stones[0];
        }
        else
        {
            return 0;
        }
    }
};
