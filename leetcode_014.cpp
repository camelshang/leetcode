// longest commom prefix
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix11(vector<string> &strs) {
  string prefix = "";
  if (strs.size() == 0)
    return prefix;

  /** check char by char, for each char, check all the string word **/
  for (int k = 0; k < strs[0].size(); k++) {
    int i = 1;
    for (; i < strs.size() && strs[i].size() > k; i++) {
      if (strs[i][k] != strs[0][k])
        return prefix;
    }
    if (i == strs.size())
      prefix += strs[0][k];
  }
  return prefix;
}

string longestCommonPrefix22(vector<string> &strs) {
  string toReturn;
  if (!strs.size())
    return toReturn;
  for (int i = 0; i < strs[0].size(); ++i) {
    char curr = strs[0][i];
    for (int j = 1; j < strs.size(); ++j) {
      if (i > strs[j].size() - 1 || curr != strs[j][i])
        return toReturn;
    }
    toReturn.push_back(curr);
  }
  return toReturn;
}

/* ========below is leetcode tutorial========= */

// tutorial1 horizontal scanning
string longestCommonPrefix(vector<string> &strs) {
  if (strs.size() == 0) {
    return "";
  }
  string prefix = strs[0]; // 初始化为第一个字符串
  for (int i = 1; i < strs.size(); i++) {
    while (strs[i].find(prefix) != 0) { // 如果找不到完整的prefix
      prefix = prefix.substr(0, prefix.length() - 1); // prefix减少最后一位
      if (prefix.empty()) {
        return "";
      }
    }
  }
  return prefix;
}

// tutorial2 vertical scanning
string longestCommonPrefix2(vector<string> &strs) {
  if (strs.size() == 0) {
    return "";
  }
  for (int i = 0; i < strs[0].length(); i++) {
    char c = strs[0].at(i);
    for (int j = 1; j < strs.size(); j++) {
      if (i == strs[j].length() || strs[j].at(i) != c) {
        return strs[0].substr(0, i);
      }
    }
  }
  return strs[0];
}

// tutorial3 divide and conquer
string commonPrefix(string lefts, string rights) {
  int minlen = min(lefts.length(), rights.length());
  for (int i = 0; i < minlen; i++) {
    if (lefts.at(i) != rights.at(i)) {
      return lefts.substr(0, i);
    }
  }
  return lefts.substr(0, minlen);
}

string longestCommonPrefix(vector<string> &strs, int left, int right) {
  if (left == right) {
    return strs[left];
  } else {
    int mid = (left + right) / 2;
    string lefts = longestCommonPrefix(strs, left, mid);
    string rights = longestCommonPrefix(strs, mid + 1, right);
    return commonPrefix(lefts, rights);
  }
}

string longestCommonPrefix3(vector<string> &strs) {
  if (strs.size() == 0) {
    return "";
  }
  return longestCommonPrefix(strs, 0, strs.size() - 1);
}

// tutorial4 binary serach
bool isCommonPrefix(vector<string> &strs, int len) {
  string strleft = strs[0].substr(0, len);
  for (int i = 1; i < strs.size(); i++) {
    if (strs[i].find(strleft) != 0) {
      return false;
    }
  }
  return true;
}

string longestCommonPrefix4(vector<string> &strs) {
  if (strs.size() == 0) {
    return "";
  }
  int minlen = std::numeric_limits<int>::max();
  for (string &s : strs) {
    minlen = min(minlen, int(s.length()));
  }
  int low = 1, high = minlen;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (isCommonPrefix(strs, mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return strs[0].substr(0, (low + high) / 2);
}

int main() {
  vector<string> strs = {"aba", "aba", "abcca"};
  string res = longestCommonPrefix4(strs);
  cout << "res " << res << endl;
}