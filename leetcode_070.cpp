// climbing stairs

// f(n) = f(n-1) + f(n-2)

// recursive -> O(2^n)   time limited
int climbStairs(int n) {
  if (n < 3) {
    return n;
  }
  return climbStairs(n - 1) + climbStairs(n - 2);
}

// bottom up calculate
int climbStairs(int n) {
  int before_one = 1, before_two = 0, res = 0;
  for (int i = 0; i < n; i++) {
    res = before_one + before_two;
    before_two = before_one;
    before_one = res;
  }
  return res;
}

int climbStairs(int n) {
  int a = 1, b = 1;
  while (n--) {
    b += a;
    a = b - a;
  }
  return a;
}

int climbStairs(int n) {
  if (n == 0 || n == 1 || n == 2) {
    return n;
  }
  int[] mem = new int[n];
  mem[0] = 1;
  mem[1] = 2;
  for (int i = 2; i < n; i++) {
    mem[i] = mem[i - 1] + mem[i - 2];
  }
  return mem[n - 1];
}