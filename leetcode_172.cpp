// factorial trailing zeros

// 0 来源于10， 而10=2*5，因此计算5的个数

// recursive
int trailingZeros(int n) { return n == 0 ? 0 : n / 5 + trailingZeros(n / 5); }

int trailingZeros(int n) {
  int cnt = 0;
  for (long long i = 5; n / i >= 1; i *= 5) { // int i maybe overflow
    cnt += n / i;
  }
}

int trailingZeroes(int n) {
  int zeros = 0;
  while (n) {
    n /= 5;
    zeros += n;
  }
  return zeros;
}