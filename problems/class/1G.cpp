/*
 * Time complexity: O(nlogn)
 * Explanation: The array is sorted (using the STL function that costs O(nlogn))
 * and, then, we iterate through all the n elements.
 *
 * Space complexity: O(n)
 * Explanation: An array is used to store the n elements.
 *
 * Idea: To get the maximum minimum distance, we need to distribute all the
 * elements in a way that an element belongs to a side and the next one of that
 * element belongs to the other side (left side > 12 and right side < 12). Using
 * this idea, we only need to find the minimum distance between two pairs of
 * elements (d[i] and d[i + 2]) because they will be nearby. Lastly, we need to
 * compare the found minimum distance with the distance between the last and
 * penultimate element because it wasn't considered before.
 */

#include <bits/stdc++.h>
#define N 55
#define C 24
using namespace std;

int n, i, maxMin, minDist;
int D[N];

int main(void) {
  scanf("%d", &n);
  for (i = 2; i < n + 2; ++i) scanf("%d", &D[i]);

  sort(D + 2, D + n + 2);

  minDist = 12;
  for (i = 2; i < n + 2; ++i) minDist = min(minDist, D[i] - D[i - 2]);
  minDist = min(minDist, (C - D[n + 1]) - D[n]);

  printf("%d\n", minDist);

  return 0;
}
