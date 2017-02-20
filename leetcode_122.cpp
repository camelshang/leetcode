// best time to buy ans sell stock 2

int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0 || prices.size() == 1)
    {
        return 0;
    }
    int maxp = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        maxp += max(prices[i + 1] - prices[i], 0);
    }
    return maxp;
}