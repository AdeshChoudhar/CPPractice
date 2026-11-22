//
// Problem: Given an image represented by an NxN matrix, where each pixel in the
//          image is 4 bytes, write a method to rotate the image by 90 degrees.
//          Can you do this in place?
//

#include "../../utils/utils.h"

void solve(vector<vector<int>>& matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  cout << "INPUT(s):" << endl;
  printMatrix(matrix, "matrix = ");

  solve(matrix);

  cout << "OUTPUT(s):" << endl;
  printMatrix(matrix, "matrix = ");

  return 0;
}
