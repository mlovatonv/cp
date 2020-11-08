/*
 * Time complexity: O(n)
 * Explanation: At maximum, it will push and pop n elements because they will
 * not be repeated. Both operations cost o(1) since we are using a deque
 * container. Also, all accesses cost o(1).
 *
 * Space complexity: O(n)
 * Explanation: An array is used to store n elements and also a set is used to
 * store m + 1 elements at most.
 *
 * Idea: Two ordered deques will keep the minimum and maximum elements. This
 * ensures us a faster access to these elements since they will be located at
 * the front. Also, elements will be deleted or inserted only 1 time during the
 * program execution.
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, c, i, j;
bool i_exists;
int a[1000005];
deque<int> _max;
deque<int> _min;

int main(void) {
  scanf("%d %d %d", &n, &m, &c);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  _max.push_back(0);
  _min.push_back(0);

  for (i = 1; i < m; ++i) {
    while (_max.size() > 0 && a[_max.back()] < a[i]) _max.pop_back();
    while (_min.size() > 0 && a[_min.back()] > a[i]) _min.pop_back();
    _max.push_back(i);
    _min.push_back(i);
  }
  if (a[_max.front()] - a[_min.front()] <= c) {
    printf("%d\n", 1);
    i_exists = true;
  }
  if (_max.front() == 0) _max.pop_front();
  if (_min.front() == 0) _min.pop_front();

  for (; i < n; ++i) {
    while (_max.size() > 0 && a[_max.back()] < a[i]) _max.pop_back();
    while (_min.size() > 0 && a[_min.back()] > a[i]) _min.pop_back();
    _max.push_back(i);
    _min.push_back(i);
    if (a[_max.front()] - a[_min.front()] <= c) {
      printf("%d\n", i - m + 2);
      i_exists = true;
    }
    if (_max.front() == i - m + 1) _max.pop_front();
    if (_min.front() == i - m + 1) _min.pop_front();
  }

  if (!i_exists) printf("NO\n");

  return 0;
}
