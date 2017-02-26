// remove duplicates from sorted array
// Given a sorted array, remove the duplicates in place such that each element
// appear only once and return the new length.
// Do not allocate extra space for another array, you must do this in place with
// constant memory.

// need get new length and the new array at the same time(in place)

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates1(vector<int> &nums) {
  if (nums.size() < 2) {
    return nums.size();
  }
  int count = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1])
      count++;
    else
      nums[i - count] = nums[i];
  }
  return nums.size() - count;
}

int removeDuplicates2(vector<int> &nums) {
  if (nums.size() < 2) {
    return nums.size();
  }
  int pos = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[pos] != nums[i]) {
      nums[++pos] = nums[i];
    }
  }
  return pos + 1;
}

int main() {
  vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
  cout << "res " << removeDuplicates2(nums) << endl;
}
