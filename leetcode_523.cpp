/* Given a list of non-negative numbers and a target integer k, write a function
to check if the array has a continuous subarray
of size at least 2 that sums up to the multiple of k, that is, sums up to n*k
where n is also an integer. */

bool checkSubarraySum(vector<int> &nums, int k) {
  int n = nums.size(), sum = 0;
  int pre = 0; // 变量pre是为了存储第一次迭代的mod值，即为了满足最少两个数的组成
  unordered_set<int> modk;
  for (int num : nums) {
    sum += num;
    int mod = (k == 0 ? sum : sum % k); // ( a + n * x) % x = a % x
    if (modk.find(mod) != modk.end()) {
      return true;
    }
    modk.insert(pre);
    pre = mod;
  }
  return false;
}