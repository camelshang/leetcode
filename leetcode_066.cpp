// plus one

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
  for (int i = digits.size(); i--; digits[i] = 0) {
    if (digits[i]++ < 9) { // 进位终于与<9的位置
      return digits;
    }
  }
  // 对于全为9的数组
  digits[0]++;
  digits.push_back(0);
  return digits;
}

// 模拟加法和进位
vector<int> plusOne2(vector<int> &digits) {
  int cary = 1, sum = 0;
  vector<int> result(digits.size(), 0);
  for (int i = digits.size() - 1; i >= 0; i--) {
    sum = cary + digits[i];
    cary = sum / 10;
    result[i] = sum % 10;
  }
  if (cary > 0) {
    result.insert(result.begin(), cary);
  }
  return result;
}

vector<int> plusOne3(vector<int> &digits) {
  for (int i = digits.size() - 1; i >= 0; i--) {
    if (digits[i] != 9) {
      digits[i]++;
      break;
    }
    digits[i] = 0;
  }
  if (digits[0] == 0)
    digits.insert(digits.begin(), 1);
  return digits;
}

int main() {
  vector<int> digits = {9, 9, 9};
  vector<int> res = plusOne(digits);
  for (auto m : res) {
    cout << m << endl;
  }
}