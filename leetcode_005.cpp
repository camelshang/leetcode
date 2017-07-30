/*
Given a string s, find the longest palindromic substring in s
*/

string longestPalindrome(string s) {
  if (s.size() < 2) {
    return s;
  }
  int beg = 0, maxlen = 1;
  for (int i = 0; i < s.size() && i + maxlen / 2 < s.size()) {
    int left = i, right = i;
    while (right < s.size() - 1 && s[right + 1] == s[right]) {
      right++;
    }
    i = right + 1;
    while (right < s.size() - 1 && left > 0 && s[right + 1] == s[left - 1]) {
      ++right;
      --left;
    }
    if (right - left + 1 > maxlen) {
      beg = left;
      maxlen = right - left + 1;
    }
  }
  return s.substr(beg, maxlen);
}