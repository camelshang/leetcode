// count and say

string genate(string s) {
  string now;
  int j = 0;
  for (int i = 0; i < s.size(); i += j) {
    for (j = 0; j + i < s.size(); j++) {
      if (s[i] != s[i + j]) {
        break;
      }
    }
    now = now + to_string(j) + s[i];
  }
  return now;
}

string countAndSay(int n) {
  string s("1");
  while (--n) {
    s = genate(s);
  }
  return s;
}

string countAndSay(int n) {
  if (n < 1)
    return "";
  string ret = "1";
  for (int i = 2; i <= n; i++) {
    string temp = "";
    int count = 1;
    char prev = ret[0];
    for (int j = 1; j < ret.size(); j++) {
      if (ret[j] == prev)
        count++;
      else {
        temp += to_string(count);
        temp.push_back(prev);
        count = 1;
        prev = ret[j];
      }
    }
    temp += to_string(count);
    temp.push_back(prev);
    ret = temp;
  }
  return ret;
}

string countAndSay(int n) {
  if (n == 0)
    return "";
  string res = "1";
  while (--n) {
    string cur = "";
    for (int i = 0; i < res.size(); i++) {
      int count = 1;
      while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
        count++;
        i++;
      }
      cur += to_string(count) + res[i];
    }
    res = cur;
  }
  return res;
}