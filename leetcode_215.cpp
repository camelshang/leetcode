/*
Find the kth largest element in an unsorted array. Note that it is the kth
largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
*/

// sort then access index
// O(nlogn) O(1)
int findKthLargest(vector<int> &nums, int k) {
  if (k <= 0 || k > nums.size()) {
    return -1;
  }
}

// quick sort parition, quick select
// worst O(n^2) best O(n) aveage O(n)
int parition(vector<int> &nums, int low, int high) {
  int pivot = nums[low];
  int i = low;
  for (int j = low + 1; j <= high; j++) {
    if (nums[j] > pivot) { // move bigger elements forward
      i++;
      swap(nums[i], nums[j]);
    }
  }
  swap(nums[i], nums[low]);
  return i;
}

int findKthLargest(vector<int> &nums, int k) {
  if (nums.size() == 0 || k <= 0 || k > nums.size()) {
    return -1;
  }
  if (nums.size() == 1) {
    return nums[0];
  }
  int low = 0, high = nums.size() - 1;
  while (true) {
    int piv = parition(nums, low, high);
    if (piv == k - 1) {
      return nums[piv];
    } else if (piv > k - 1) {
      high = piv - 1;
    } else {
      low = piv + 1;
    }
  }
}

// heap sort
// O(nlogk)
void max_heapify(vector<int> &nums, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && nums[left] > nums[largest])
    largest = left;
  if (right < n && nums[right] > nums[largest])
    largest = right;
  if (largest != i) {
    swap(nums[largest], nums[i]);
    max_heapify(nums, n, largest);
  }
}

void build_max_heap(vector<int> &nums, int n) {
  for (int i = (n >> 1) - 1; i >= 0; i--) {
    max_heapify(nums, n, i);
  }
}

int findKthLargest(vector<int> &nums, int k) {
  int n = nums.size();
  build_max_heap(nums, n);
  for (int i = 0; i < k; i++) {
    swap(nums[0], nums[n - 1]);
    n--;
    max_heapify(nums, n, 0);
  }
  return nums[n];
}

// heap sort with built-in priority_queue
// O(nlogk)
int findKthLargest(vector<int> &nums, int k) {
  priority_queue<int> pq(nums.begin(), nums.end());
  for (int i = 0; i < k - 1; i++) {
    pq.pop();
  }
  return pq.top();
}