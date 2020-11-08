int r[maxn], f[maxn], rf[maxn];

int mul(ll a, ll b) { return a * b % mod; }

void build() {
  r[1] = f[0] = rf[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    if (i > 1) r[i] = mul(mod - r[mod % i], mod / i);
    f[i] = mul(f[i - 1], i);
    rf[i] = mul(rf[i - 1], r[i]);
  }
}

int comb(int n, int m) {
  if (n < m) return 0;
  return mul(f[n], mul(rf[m], rf[n - m]));
}
