// roman to integer

// roman rules
// I V  X  L   C   D    M
// 1 5 10 50 100 500 1000
/*计数规则：
相同的数字连写，所表示的数等于这些数字相加得到的数，例如：III = 3;
小的数字在大的数字右边，所表示的数等于这些数字相加得到的数，例如：VIII = 8;
小的数字，限于（I、X和C）在大的数字左边，所表示的数等于大数减去小数所得的数，例如：IV=4;
正常使用时，连续的数字重复不得超过三次;
在一个数的上面画横线，表示这个数扩大1000倍（本题只考虑3999以内的数，所以用不到这条规则.
*/

#include <iostream>
#include <string>

int romanToInt(string s) {
  if (s.empty()) {
    return -1;
  }
  int res = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    switch (s.at(i)) {
    case 'I':
      res += (res >= 5 ? -1 : 1);
      break;
    case 'V':
      res += 5;
      break;
    case 'X':
      res += 10 * (res >= 50 ? -1 : 1);
      break;
    case 'L':
      res += 50;
      break;
    case 'C':
      res += 100 * (res >= 500 ? -1 : 1);
      break;
    case 'D':
      res += 500;
      break;
    case 'M':
      res += 1000;
      break;
    }
  }
  return res;
}

int romanToInt2(string s) {
  if (s.empty()) {
    return -1;
  }
  unordered_map<char, int> m;
  m['I'] = 1;
  m['V'] = 5;
  m['X'] = 10;
  m['L'] = 50;
  m['C'] = 100;
  m['D'] = 500;
  m['M'] = 1000;
  int ans = m[s[s.length() - 1]];
  for (int i = s.length() - 2; i >= 0; i--) {
    if (m[s[i]] < m[s[i + 1]]) {
      ans -= m[s[i]];
    } else {
      ans += m[s[i]];
    }
  }
  return ans;
}
