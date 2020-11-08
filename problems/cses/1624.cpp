#include <bits/stdc++.h>
#define BOARD_SIZE 8
#define N_QUEENS 8
using namespace std;

char b[BOARD_SIZE][BOARD_SIZE];
int cols[BOARD_SIZE];
int diag1[2 * BOARD_SIZE], diag2[2 * BOARD_SIZE];
int c;

bool x(int col, int row, int d1, int d2) {
  if (b[row][col] == '*') return true;
  for (int i = 0; i < col + 1; ++i) {
    for (int j = 0; j < col + 1; ++j)
      if (i != j && cols[i] == cols[j]) return true;
  }
  if (diag1[d1] || diag2[d2]) return true;
  return false;
}

void r(int l) {
  if (l == N_QUEENS) {
    ++c;
    return;
  }
  int d1, d2;
  for (int i = 0; i < BOARD_SIZE; ++i) {
    cols[l] = i;
    d1 = i - l + BOARD_SIZE - 1;
    d2 = i + l;
    if (x(l, i, d1, d2)) continue;
    diag1[d1] = diag2[d2] = 1;
    r(l + 1);
    diag1[d1] = diag2[d2] = 0;
  }
}

int main() {
  for (int i = 0; i < BOARD_SIZE; ++i)
    for (int j = 0; j < BOARD_SIZE; ++j) cin >> b[i][j];
  r(0);
  cout << c << endl;
  return 0;
}
