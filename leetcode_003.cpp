#include <algorithm>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
  const int ASCII_MAX = 255;
  int last[ASCII_MAX]; // last alpha occurs postion
  int start = 0;

  fill(last, last + ASCII_MAX, -1);
  int max_len = 0;
  for (int i = 0; i < s.size(); i++) {
    cout << "i " << i << " and  s[i] " << s[i] << " and last[s[i]] "
         << last[s[i]] << endl;
    if (last[s[i]] >= start) {
      max_len = max(i - start, max_len);
      start = last[s[i]] + 1;
      cout << "max length " << max_len << " and start " << start << endl;
    }
    last[s[i]] = i;
  }
  return max((int)s.size() - start, max_len);
}

int lengthOfLongestSubstring2(string s) {
  const int ASCII_MAX = 256;
  int start = -1;
  int maxlen = 0;
  vector<int> dict(ASCII_MAX, -1);
  for (int i = 0; i < s.length(); i++) {
    if (dict[s[i]] > start) {
      start = dict[s[i]];
    }
    dict[s[i]] = i;
    maxlen = max(maxlen, i - start);
  }
}

int main() {
  string s = "bcdacd";
  cout << lengthOfLongestSubstring(s);
}