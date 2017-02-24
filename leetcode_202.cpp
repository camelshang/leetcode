// happy number

// Floyd's cycle detection

int next(int n) {
  int sum = 0;
  while (n != 0) {
    sum += pow(n % 10, 2);
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  int slow = next(n);
  int fast = next(next(n));
  while (slow != fast) {
    slow = next(slow);
    fast = next(next(fast));
  }
  return fast == 1;
}

// hash table
bool isHappy(int n) {
  unordered_map<int, bool> m;
  int num = 0;
  m[n] = 1;
  while (n != 1) {
    while (n) {
      num += (n % 10) * (n % 10);
      n /= 10;
    }
    if (m[num]) {
      break;
    } else {
      m[num] = 1;
    }
    n = num;
    num = 0;
  }
  return 1 == n;
}