#include <bits/stdc++.h>
#define N 1000
using namespace std;

int n, x;
int weight[N];
pair<int, int> best[1 << N];

int main(void) {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> weight[i];

  best[0] = {1, 0};

  /* Itera sobre los subconjuntos */
  for (int s = 1; s < (1 << n); ++s) {
    best[s] = {n + 1, 0};
    for (int p = 0; p < n; ++p) /* Itera sobre los elementos de s */
      /* Chequea si p esta en el conjunto */
      if (s & (1 << p)) {
        /* Quita a p del conjunto */
        auto option = best[s ^ (1 << p)];
        /* Adiciono p a una particion existente */
        if (option.second + weight[p] <= x) {
          option.second += weight[p];
        } else {
          ++option.first;
          option.second = weight[p];
        }
        /* min en pares, chequea el primero, despues el segundo */
        best[s] = min(best[s], option);
      }
  }

  cout << best[(1 << n) - 1].first << endl;

  return 0;
}
