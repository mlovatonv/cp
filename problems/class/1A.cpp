/*
 * Time complexity: O(n^3)
 * Explanation: The triples are generated sequentially and each one is checked
 * by a given condition.
 *
 * Space complexity: O(n)
 * Explanation: All the n elements are stored in a vector.
 *
 * Idea: "The triangle inequality states that the sum of the lengths of any two
 * sides of a triangle must be greater than or equal to the length of the third
 * side" (Wikipedia). Using this condition, the program sorts the received
 * vector in an ascending order and, then, it iterates through the triples
 * sequentially and check if they form a valid triangle by comparing the sum of
 * the first two values to the third one. In this case, degenerated triangles
 * are excluded.
 */

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n, i, j, k, li, c;
vi l;

int main(void) {
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> li;
    l.push_back(li);
  }
  sort(l.begin(), l.end());
  for (i = 0; i < n - 2; ++i)
    for (j = i + 1; j < n - 1; ++j)
      for (k = j + 1; k < n; ++k)
        if (l[i] + l[j] > l[k]) ++c;
  cout << c << endl;
  return 0;
}
