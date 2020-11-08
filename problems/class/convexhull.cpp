#include <bits/stdc++.h>
using namespace std;

const int N = 2e+5 + 2;
const int P = 1e+3 + 2;
int n;
vector<double> p, d, u(N);
/* interv[i].first guarda el punto final de i-esimo intervalo
 * interv[i].second guarda el item asociado al i-esimo intervalo*/
vector<pair<double, int>> interv;

inline double interseccion(int i, int k) {
  return (u[i] - u[k]) / (d[k] - d[i]);
}

int main(void) {
  cin >> n;
  p.push_back(0);
  for (int i = 1; i <= n; ++i) {
    double a;
    cin >> a;
    p.push_back(a);
  }
  d.push_back(1);
  for (int i = 1; i <= n; ++i) {
    double a;
    cin >> a;
    d.push_back(a);
  }
  interv.push_back({P, 0});
  for (int i = 1; i <= n; ++i) {
    double x = p[i];
    auto idx = lower_bound(interv.begin(), interv.end(), make_pair(x, 0)) -
               interv.begin();
    int j = interv[idx].second;
    /* optimo de i */
    u[i] = u[j] + d[j] * x;

    /* insertar nueva recta */
    while (interv.size() > 0) {
      /* num de intervalos */
      int l = interv.size();
      /* item asociado al ultimo intervalo */
      int k = interv[l - 1].second;
      /* punto de interseccion entre fi y fk */
      auto xx = interseccion(i, k);
      /* fi tapa a fk */
      if (l > 2 && xx < interv[l - 2].first) {
        interv.pop_back();
      } else {
        interv[l - 1].first = xx;
        interv.push_back({P, i});
        break;
      }
    }
  }
  cout << u[n] << endl;
  return 0;
}
