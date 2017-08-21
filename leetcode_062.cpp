/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

How many possible unique paths are there?
*/

// from total steps (m+n-2) choose (m-1) step to go down
// or (n-1) step to go right)
// n!/((n-k)! k!) = n(n-1)...(n-k+1) / k(k-1)...1
int uniquePaths(int m, int n) {
  int N = m + n - 2;
  int k = min(m - 1, n - 1);
  long res = 1; // int possible overflow
  for (int i = 1; i <= k; i++) {
    res = res * (N - k + i) / i; // res = res * (N-i+1)/i;
  }
  return (int)res;
}

// dynamic programming
// P[i][j] = P[i - 1][j] + P[i][j - 1]
int uniquePaths(int m, int n) {
  if (m <= 0 || n <= 0)
    return 0;
  vector<vector<int>> res(m, vector<int>(n, 1));
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      res[i][j] = res[i - 1][j] + res[i][j - 1];
    }
  }
  return res[m - 1][n - 1];
}
// only save left column and current column
int uniquePaths(int m, int n) {
  if (m > n) {
    return uniquePaths(n, m);
  }
  vector<int> precol(m, 1);
  vector<int> curcol(m, 1);
  for (int j = 1; j < n; j++) {
    for (int i = 1; i < m; i++) {
      curcol[i] = curcol[i - 1] + precol[i];
    }
    swap(precol, curcol);
  }
  return pre[m - 1];
}
// precol[i] just curcol[i] not updated
int uniquePaths(int m, int n) {
  if (m > n) {
    return uniquePaths(n, m);
    vector<int> curcol(m, 1);
    for (int j = 1; j < n; j++) {
      for (int i = 1; i < m; i++) {
        curcol[i] += curcol[i - 1];
      }
    }
    return curcol[m - 1];
  }
}