/*
 * Time complexity: O(n!)
 * Explanation: All the permutations of n points are generated and a distance is
 * calculated for each permutation.
 *
 * Space complexity: O(2n)
 * Explanation: All the n pair of points are stored in a vector.
 *
 * Idea: Generate all the permutations and calculate the distance for each one.
 * Then, divide the sum of the distance by the number of permutations.
 */

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using vi = vector<ii>;

int n, i, x, y, c;
double a;
vi xy;

inline double d(ii p1, ii p2) {
  return sqrt(pow(p2.first - p1.first, 2.0) + pow(p2.second - p1.second, 2.0));
}

int main(void) {
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> x;
    cin >> y;
    xy.push_back(make_pair(x, y));
  }
  sort(xy.begin(), xy.end());
  do {
    ++c;
    for (i = 0; i < n - 1; ++i) a += d(xy[i], xy[i + 1]);
  } while (next_permutation(xy.begin(), xy.end()));
  printf("%.12f", a / c);
  return 0;
}
