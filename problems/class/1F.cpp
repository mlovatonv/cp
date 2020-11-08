/*
 * Time complexity: O(nlogn)
 * Explanation: n insertions (each insertion cost logn), n - m deletions (each
 * deletion costs logn)
 *
 * Space complexity: O(n)
 * Explanation: An array is used to store n elements and also a set is used to
 * store m + 1 elements at most.
 *
 * Idea: An ordered set sorts the elements as they are inserted and, in case of
 * pairs, the first element is used for the comparison. Using this structure, a
 * pair of integers (value, index) are stored and removed when they cannot be
 * considered for the sample anymore. The maximum value can be obtained as the
 * last element of the set and the minimum value as the first one. The
 * insertions and deletions are logn since the set is ordered.
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, c, i, j;
bool i_exists;
int a[1000005];
set<pair<int, int>> o;

int main(void) {
  scanf("%d %d %d", &n, &m, &c);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < m; ++i) {
    o.emplace(a[i], i);
  }
  if ((*o.rbegin()).first - (*o.begin()).first <= c) {
    printf("%d\n", 1);
    i_exists = true;
  }
  o.erase(o.find({a[0], 0}));

  for (; i < n; ++i) {
    o.emplace(a[i], i);
    if ((*o.rbegin()).first - (*o.begin()).first <= c) {
      printf("%d\n", i - m + 2);
      i_exists = true;
    }
    o.erase(o.find({a[i - m + 1], i - m + 1}));
  }

  if (!i_exists) printf("NO\n");

  return 0;
}
