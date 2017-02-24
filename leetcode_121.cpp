// best time to buy and sell stock 1

int maxProfit(vector<int> &prices) {
  if (prices.empty()) {
    return NULL;
  }
  if (prices.size() == 1) {
    return 0;
  }
  int res = 0, min = prices[0];
  for (auto p : prices) {
    if (p < min) {
      min = p;
    } else {
      res = max(p - min, res);
    }
  }
  return res;
}