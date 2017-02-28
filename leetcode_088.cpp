// merege sorted array

void merge(vector<int> &nums1, int m, vector<int> &nums, int n) {
  int i = m - 1, j = n - 1, tra = m + n - 1;
  while (j >= 0) {
    if (i >= 0 && nums1[i] > nums2[j]) {
      nums1[tra--] = nums1[i--];
    } else {
      nums1[tra--] = nums2[j--];
    }
  }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  while (n > 0) {
    nums1[m + n - 1] =
        (m == 0 || nums2[n - 1] > nums1[m - 1]) ? nums2[--n] : nums1[--m];
  }
}