// maximum subarray

//借鉴 Kadane's algorithm
int maxSubArray(vector<int> &nums) {
  if (nums.empty()) {
    return NULL;
  }
  if (nums.size() == 1) {
    return nums[0];
  }
  int maxCur = 0, maxFin = nums[0];
  for (auto &num : nums) {
    maxCur = max(num, maxCur + num);
    maxFin = max(maxFin, maxCur);
  }
  return maxFin;
}