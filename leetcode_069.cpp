// sqrt

// binary search
int sqrt(int x) {
  if (0 == x)
    return 0;
  int left = 1, right = x, ans;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mid <= x / mid) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }
  return ans;
}

// newton method
int mySqrt(int x) {
  long r = (x + 1) / 2;
  while (r * r > x) {
    r = (r + x / r) / 2;
  }
  return r;
}

// bit
int mySqrt(int x) {
  long ans = 0;
  long bit = 1l << 16;
  while (bit > 0) {
    ans |= bit;
    if (ans * ans > x) {
      ans ^= bit;
    }
    bit >>= 1;
  }
  return (int)ans;
}