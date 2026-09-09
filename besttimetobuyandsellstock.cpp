#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {

            // Find minimum buying price
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }

            // Calculate today's profit
            int profit = prices[i] - minPrice;

            // Update maximum profit
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};

int main()
{

    Solution solution;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = solution.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}