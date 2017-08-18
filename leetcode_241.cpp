/*
Given a string of numbers and operators, return all possible results from
computing all the different possible ways to group numbers and operators. The
valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]
*/

vector<int> diffWaysToCompute(string input) {
  vector<int> res;
  for (int i = 0; i < input.size(); i++) {
    char cur = input[i];
    if (cur == '+' || cur == '-' || cur == '*') {
      vector<int> res1 = diffWaysToCompute(input.substr(0, i));
      vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
      for (auto r1 : res1) {
        for (auto r2 : res2) {
          if (cur == '+') {
            res.push_back(r1 + r2);
          } else if (cur == '-') {
            res.push_back(r1 - r2);
          } else if (cur == '*') {
            res.push_back(r1 * r2);
          }
        }
      }
    }
  }
  if (res.empty()) {
    res.push_back(atoi(input.c_str()));
  }
  return res;
}

// remove repeated computation of the same string
vector<int> diffWaysToCompute(string input) {
  unordered_map<string, vector<int>> m;
  return compute(input, m);
}

vector<int> getResFromString(string ss, vector<string, vector<int>> &m) {
  if (m.find(ss) != m.end()) {
    return m[ss];
  } else {
    return compute(ss, m);
  }
}
vector<int> compute(string input, unordered_map<string, vector<int>> &m) {
  vector<int> res;
  for (int i = 0; i < input.size(); i++) {
    char cur = input[i];
    if (cur == '+' || cur == '-' || cur == '*') {
      vector<int> res1, res2;
      string ss = input.substr(0, i);
      res1 = getResFromString(ss, m);
      ss = input.substr(i + 1);
      res2 = getResFromString(ss, m);
      for (auto r1 : res1) {
        for (auto r2 : res2) {
          if (cur == '+') {
            res.push_back(r1 + r2);
          } else if (cur == '-') {
            res.push_back(r1 - r2);
          } else if (cur == '*') {
            res.push_back(r1 * r2);
          }
        }
      }
    }
  }
  if (res.empty()) {
    res.push_back(atoi(input.c_str()));
  }
  m[input] = res;
  return res;
}