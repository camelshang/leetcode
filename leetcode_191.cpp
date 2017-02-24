// number of 1 bits

int hammingWeight(uint32_t n) {
  int res = 0;
  while (n) {
    n &= (n - 1); // trick,将最后一个1置0
    res++;
  }
  return res;
}

int hammingWeight(uint32_t n) {
  int count = 0;
  unsigned int temp;
  for (int i = 0; i < 32; i++) {
    temp = n & (1 << i);
    if (temp > 0)
      count++;
  }

  return count;
}