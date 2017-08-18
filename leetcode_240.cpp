/*
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int row = matrix.size();
  if (row == 0) {
    return false;
  }
  int col = matrix[0].size();
  int i = 0, j = col - 1;
  while (i < row && j >= 0) {
    if (matrix[i][j] == target) {
      return true;
    } else if (matrix[i][j] > target) {
      j--;
    } else {
      i++;
    }
  }
  return false;
}
