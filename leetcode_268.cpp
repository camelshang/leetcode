// missing number

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 对比[0-n]与nums数组
int missingNumber(vector<int> &nums) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  vector<int> m;
  for (int i = 0; i <= n; i++) {
    m.push_back(i);
  }
  for (auto mm : m) {
    if (find(nums.begin(), nums.end(), mm) == nums.end()) {
      return mm;
    }
  }
  return 0;
}

// sum([0-n]) - sum(nums)
int missingNumber(vector<int> &nums) {
  int res = nums.size();
  for (int i = 0; i < nums.size(); i++) {
    res += i - nums[i];
  }
  return res;
}

// xor
int missingNumber(vector<int> &nums) {
  int res = 0, i = 0;
  for (; i < nums.size(); i++) {
    res = res ^ i ^ nums[i];
  }
  return res ^ i;
}

// binary search
int missingNumber(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int left = 0, right = nums.size();
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] > mid) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  vector<int> nums = {0, 3, 1};
  cout << missingNumber(nums) << endl;
}