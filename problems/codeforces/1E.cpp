/*
 * Time complexity: O(log p)
 * Explanation: The search is iterated a fixed number of times that depends on
 * the size of p.
 *
 * Space complexity: O(1)
 * Explanation: No structures are used to store values.
 *
 * Idea: Given the equation to find the total number of months, a ternary search
 * is used to find the real number that minimizes the equation.
 */

#include <bits/stdc++.h>
using namespace std;

double p, l, r, s, m1, m2, t1, t2;
int it = 200;

inline double t(double x) { return x + p / pow(2, x / 1.5); }

int main(void) {
  cin >> p;
  l = 0;
  r = p;
  while (--it) {
    m1 = (l * 2 + r) / 3;
    m2 = (l + 2 * r) / 3;
    t1 = t(m1);
    t2 = t(m2);
    if (t1 < t2) {
      s = t1;
      r = m2;
    } else {
      s = t2;
      l = m1;
    }
  }
  printf("%.14f", s);
  return 0;
}
