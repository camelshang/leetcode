// intersection of two arrays

// hash table
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  vector<int> res;
  if (nums1.size() == 0 || nums2.size() == 0) {
    return res;
  }
  if (nums1.size() > nums2.size()) {
    intersect(nums2, nums1);
  }
  unordered_map<int, int> m;
  for (auto num1 : nums1) {
    m[num1]++;
  }
  for (auto num2 : nums2) {
    if (m.find(num2) != m.end() && m[num2] > 0) {
      res.push_back(num2);
      m[num2]--;
    }
  }
  return res;
}

// sort and two pointers
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  vector<int> res;
  int n1 = nums1.size(), n2 = nums2.size();
  if (n1 == 0 || n2 == 0) {
    return res;
  }
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int i1 = 0, i2 = 0;
  while (i1 < n1 && i2 < n2) {
    if (nums1[i1] == nums2[i2]) {
      res.push_back(nums1[i1]);
      i1++;
      i2++;
    } else if (nums1[i1] > nums2[i2]) {
      i2++;
    } else {
      i1++;
    }
  }
  return res;
}