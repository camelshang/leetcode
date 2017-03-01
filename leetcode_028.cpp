// implement strStr()
// check str A is a part of str B

int strStr(string haystack, string needle) {
  if (needle.empty()) {
    return 0;
  }
  int m = haystack.length();
  int n = needle.length();
  if (n > m) {
    return -1;
  }
  for (int i = 0; i <= m - n; i++) {
    for (int j = 0; j < n; j++) {
      if (haystack.at(i + j) != needle.at(j)) {
        break;
      }
      if (j == n - 1) {
        return i;
      }
    }
  }
  return -1;
}

int strStr(string haystack, string needle) {
  for (int i = 0;; i++) {
    for (int j = 0;; j++) {
      if (j == needle.length())
        return i;
      if (i + j == haystack.length())
        return -1;
      if (needle.at(j) != haystack.at(i + j))
        break;
    }
  }
}