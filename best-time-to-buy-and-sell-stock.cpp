#include <vector>
using std::vector;

class Solution {
public:
    /*
    * The naive O(n^2) solution is to simply check ALL combinations of pairs.
    * An O(n) solution would be to use the sliding window technique
    * Source: https://www.geeksforgeeks.org/window-sliding-technique/
    * Variable 'oiled_min' holds the minimum price on each iteration,
    * and a "max profit" would be the highest difference between current window
    * and the known minimum to the left. */

    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        // Assumes prices.size() > 0
        int oiled_min = prices[0];

        for (unsigned int i = 1; i < prices.size(); i++) {
           // Search for new minimum in oiled section
            if (prices[i] < oiled_min)
               oiled_min = prices[i];

            // See if current difference between window and minimum exceeds current max_profit
            if (prices[i] - oiled_min > max_profit)
                max_profit = prices[i] - oiled_min;
        }
        return max_profit;

    }
};
