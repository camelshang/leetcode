/* Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead. */
int minSubArrayLen(int s, vector<int> &nums) {
  if (nums.empty()) {
    return 0;
  }
  int i = 0, j = 0, sum = 0, imin = INT_MAX;
  while (j < nums.size()) {
    sum += nums[j++];
    while (sum >= s) {
      imin = min(imin, j - 1);
      sum -= nums[i++];
    }
  }
  return imin == INT_MAX ? 0 : imin;
}