// hosue robber

// DP f(n)=max(f(n-2)+nums[n], f(n-1))
// simple, repeated space occupacy
int rob(vector<int> &nums) {
  if (numes.empty())
    return 0;
  else if (nums.size() == 1)
    return nums[0];
  else if (nums.size() == 2)
    return max(nums[0], nums[1]);
  int n = nums.size();
  vector<int> robm(n, 0);
  robm[0] = nums[0];
  robm[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n; i++) {
    robm[i] = max(robm[i - 2] + nums[i], robm[i - 1]);
  }
  return robm[n - 1];
}

int rob(vector<int> &nums) {
  int pre = 0, cur = 0;
  for (auto &num : nums) {
    int temp = max(pre + num, cur);
    pre = cur;
    cur = temp;
  }
  return cur;
}

int rob(vector<int> &nums) {
  int a = 0;
  int b = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (i % 2 == 0) {
      a = max(a + nums[i], b);
    } else {
      b = max(a, b + nums[i]);
    }
  }
  return max(a, b);
}

// DP
int rob(vector<int> &num) {
  int n = num.size();
  if (n == 0)
    return 0;
  vector<int> result(n + 1, 0);
  result[1] = num[0];
  for (int i = 2; i <= n; i++) {
    result[i] = max(result[i - 1], result[i - 2] + num[i - 1]);
  }
  return result[n];
}

int main() {
  vector<int> nums = {15, 1, 1, 4, 2, 5, 6, 8};
  cout << "res " << rob(nums) << endl;
}