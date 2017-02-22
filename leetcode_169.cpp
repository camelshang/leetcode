// majority element

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// hash table
int majorityElement(vector<int> &nums) {
  int len = nums.size();
  unordered_map<int, int> m;
  for (auto num : nums) {
    if (++m[num] > len / 2) {
      return num;
    }
  }
  return 0;
}

// must appear in [n/2] position

int majorityElement2(vector<int> &nums) {
  nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
  return nums[nums.size() / 2];
}

// brilliant idea, Moore's voting algorithm
int majorityElement3(vector<int> &nums) {
  int nTimes = 0;
  int candidate = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nTimes == 0) {
      candidate = nums[i];
      nTimes = 1;
    } else {
      if (candidate == nums[i]) {
        nTimes++;
        if (nTimes > nums.size() / 2) {
          return candidate;
        }
      } else {
        nTimes--;
      }
    }
    cout << "cand " << candidate << " ntime " << nTimes << endl;
  }
  return candidate;
}

// divide and conquer

int majority(vector<int> &nums, int left, int right) {
  if (left == right)
    return nums[left];
  int mid = left + ((right - left) >> 1);
  int lm = majority(nums, left, mid);
  int rm = majority(nums, mid + 1, right);
  if (lm == rm)
    return lm;
  return count(nums.begin() + left, nums.begin() + right + 1, lm) >
                 count(nums.begin() + left, nums.begin() + right + 1, rm)
             ? lm
             : rm;
}

int majorityElement4(vector<int> &nums) {
  return majority(nums, 0, nums.size() - 1);
}

// bit manipulation
int majorityElement5(vector<int> &nums) {
  int major = 0, n = nums.size();
  for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
    int bitCounts = 0;
    for (int j = 0; j < n; j++) {
      if (nums[j] & mask)
        bitCounts++;
      if (bitCounts > n / 2) {
        major |= mask;
        break;
      }
    }
  }
  return major;
}

int main() {
  vector<int> nums = {1, 3, 3, 3, 5, 2, 3, 3};
  cout << majorityElement3(nums) << endl;
}