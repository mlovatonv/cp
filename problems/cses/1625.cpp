#include <bits/stdc++.h>
#define PATH_SIZE 48

using namespace std;

int c;
string input_path;
int visited[7][7];

inline bool invalid(int i, int a, int b) {
  return a < 0 || b < 0 || 6 < a || 6 < b || visited[a][b] ||
         (i != PATH_SIZE && a == 0 && b == 6);
}

void search(int i, int a, int b) {
  if (invalid(i, a, b)) return;
  if (i == PATH_SIZE) {
    if (a == 0 && b == 6) ++c;
    return;
  }

  visited[a][b] = 1;

  if (input_path[i] == '?') {
    if (a == 0) {
      if (0 < b && b < 6 && !visited[a][b - 1] && !visited[a][b + 1]) {
        visited[a][b] = 0;
        return;
      }
      search(i + 1, a + 1, b);
      search(i + 1, a, b + 1);
    } else if (b == 0) {
      if (a < 6 && !visited[a - 1][b] && !visited[a + 1][b]) {
        visited[a][b] = 0;
        return;
      }
      search(i + 1, a + 1, b);
      search(i + 1, a, b + 1);
    } else if (a == 6) {
      if (b < 6 && !visited[a][b - 1] && !visited[a][b + 1]) {
        visited[a][b] = 0;
        return;
      }
      search(i + 1, a, b + 1);
      search(i + 1, a - 1, b);
    } else if (b == 6) {
      if (!visited[a - 1][b] && !visited[a + 1][b]) {
        visited[a][b] = 0;
        return;
      }
      search(i + 1, a, b - 1);
      search(i + 1, a - 1, b);
    } else if (visited[a - 1][b] && visited[a + 1][b] && !visited[a][b - 1] &&
               !visited[a][b + 1]) {
      visited[a][b] = 0;
      return;
    } else if (visited[a][b - 1] && visited[a][b + 1] && !visited[a - 1][b] &&
               !visited[a + 1][b]) {
      visited[a][b] = 0;
      return;
    } else {
      search(i + 1, a - 1, b);
      search(i + 1, a, b - 1);
      search(i + 1, a, b + 1);
      search(i + 1, a + 1, b);
    }
  } else if (input_path[i] == 'D') {
    search(i + 1, a, b + 1);
  } else if (input_path[i] == 'U') {
    search(i + 1, a, b - 1);
  } else if (input_path[i] == 'L') {
    search(i + 1, a - 1, b);
  } else if (input_path[i] == 'R') {
    search(i + 1, a + 1, b);
  }

  visited[a][b] = 0;
}

int main() {
  input_path.resize(PATH_SIZE);
  cin >> input_path;
  search(0, 0, 0);
  cout << c << endl;
  return 0;
}
