#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, a, p, sum;
int invalid[N];
vector<int> A;
priority_queue<pair<int, int>> pq;

int main(void) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < A.size(); ++i) {
    sum += A[i];
    if (A[i + 1] > A[i] || i == A.size() - 1) {
      pq.push({sum, A[i]});
      sum = 0;
    }
  }
  while (!pq.empty()) {
    if (!invalid[pq.top().second]) {
      p += pq.top().first;
      invalid[pq.top().second + 1] = 1;
      invalid[pq.top().second - 1] = 1;
    }
    pq.pop();
  }
  cout << p << endl;
  return 0;
}
