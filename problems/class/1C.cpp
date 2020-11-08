/*
 * Time complexity: O(n)
 * Explanation: The program iterates through all n the elements.
 *
 * Space complexity: O(n)
 * Explanation: The n elements are stored in a vector.
 *
 * Idea: Remove the TVs until a TV channel matches its index and, then, continue
 * until the end of the vector.
 */

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n, i, j = 1, k, ai;
vi a;

int main(void) {
  cin >> n;
  for (; i < n; ++i) {
    cin >> ai;
    a.push_back(ai);
  }
  for (i = 0; i < n; ++i) {
    if (a[i] == j)
      ++j;
    else
      ++k;
  }
  k = k > n - 1 ? -1 : k;
  cout << k << endl;
  return 0;
}
