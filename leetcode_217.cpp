// contains duplicate

// hash table
bool containsDuplicate(vector<int> &nums) {
  if (nums.empty() || nums.size() == 1) {
    return false;
  }
  unordered_map<int, int> m;
  for (auto &num : nums) {
    if (++m[num] >= 2) {
      return true;
    }
  }
  return false;
}

// hash table 2
bool containsDuplicate(vector<int> &nums) {
  if (nums.empty() || nums.size() == 1) {
    return false;
  }
  unordered_map<int, int> m;
  for (auto &num : nums) {
    if (m.find(num) != m.end()) {
      return true;
    } else {
      m[num]++;
    }
  }
  return false;
}

// set
bool containsDuplicate(vector<int> &nums) {
  if (nums.empty() || nums.size() == 1) {
    return false;
  }
  unordered_set<int> s;
  for (auto &num : nums) {
    if (s.find(num) != s.end()) {
      return true;
    } else {
      s.insert(num);
    }
  }
  return false;
}

// sort
bool containsDuplicate(vector<int> &nums) {
  if (nums.empty() || nums.size() == 1) {
    return false;
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      return true;
    }
  }
  return false;
}

// one line with set
bool containsDuplicate(vector<int> &nums) {
  return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
}

// not yet for me
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N / BITSPERWORD];
void set_(int i) { a[i >> SHIFT] |= (1 << (i & MASK)); }
void clr(int i) { a[i >> SHIFT] &= ~(1 << (i & MASK)); }
int test(int i) { return a[i >> SHIFT] & (1 << (i & MASK)); }

class Solution {

public:
  bool containsDuplicate(vector<int> &nums) {
    if (nums.size() == 0)
      return false;
    int i;
    for (i = 0; i < nums.size(); i++)
      clr(nums[i]);
    for (i = 0; i < nums.size(); i++) {
      if (test(nums[i]))
        return true;
      else
        set_(nums[i]);
    }
    return false;
  }
};