// power of three

bool isPowerOfThree(int n) {
  if (n > 1) {
    while (n % 3 == 0) {
      n /= 3;
    }
  }
  return n == 1;
}

bool isPowerOfThree(int n) {
  if (n < 1) {
    return 0;
  }
  double r = log10(n) / log10(3);
  if (floor(r) == r) {
    return 1;
  } else {
    return 0;
  }
}

bool isPowerOfThree(int n) {
  if (n <= 0)
    return false;
  int t = pow(3, (int)(log(INT_MAX) / log(3)));
  return (t % n == 0);
}