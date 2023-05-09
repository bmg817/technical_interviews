class Solution
{
public:
    // 121. Best Time to Buy and Sell Stock: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    // Time complexity: O(n)
    // Space complexity: O(1)

    int maxProfit(const vector<int> &prices)
    {
        int buy = prices[0];
        int maxProfit = 0;

        // Loop through each price values in the prices array
        // Store the minimum value of all inspected values in the buy variable
        // Find the max profit by subtracting the current price value 
        // from the smallest value that's been seen up to this point
        for (int i = 1; i < prices.size(); i++)
        {
            buy = min(buy, price);
            maxProfit = max(price - buy, maxProfit);
        }

        return maxProfit;
    }
};