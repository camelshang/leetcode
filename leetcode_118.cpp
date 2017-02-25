// pascal's triangle

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> res(numRows);
  if (numRows < 1) {
    return res;
  }
  for (int i = 0; i < numRows; i++) {
    res[i].resize(i + 1);
    res[i][0] = res[i][i] = 1;
    for (int j = 1; j < i; j++) {
      res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
  }
  return res;
}

int main() {
  vector<vector<int>> res = generate(5);
  for (auto v : res) {
    cout << "line " << endl;
    for (auto m : v) {
      cout << m << " ";
    }
    cout << endl;
  }
}