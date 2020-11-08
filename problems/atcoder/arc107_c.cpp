// https://drken1215.hatenablog.com/entry/2020/10/31/234100

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

struct UnionFind {
  vector<int> par;
  
  UnionFind(int n) : par(n, -1) { }
  void init(int n) { par.assign(n, -1); }
  
  int root(int x) {
  if (par[x] < 0) return x;
  else return par[x] = root(par[x]);
  }
  
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  
  int size(int x) {
    return -par[root(x)];
  }
};

// modint
template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() const { return MOD; }
  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr istream& operator >> (istream& is, Fp<MOD>& x) noexcept {
    is >> x.val;
    x.val %= MOD;
    if (x.val < 0) x.val += MOD;
    return is;
  }
  friend constexpr ostream& operator << (ostream& os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD>& r, long long n) noexcept {
    if (n == 0) return 1;
    if (n < 0) return modpow(modinv(r), -n);
    auto t = modpow(r, n / 2);
    t = t * t;
    if (n & 1) t = t * r;
    return t;
  }
  friend constexpr Fp<MOD> modinv(const Fp<MOD>& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    return Fp<MOD>(u);
  }
};

template<class T> struct BiCoef {
  vector<T> fact_, inv_, finv_;
  constexpr BiCoef() {}
  constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
    init(n);
  }
  constexpr void init(int n) noexcept {
    fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
    int MOD = fact_[0].getmod();
    for(int i = 2; i < n; i++){
      fact_[i] = fact_[i-1] * i;
      inv_[i] = -inv_[MOD%i] * (MOD/i);
      finv_[i] = finv_[i-1] * inv_[i];
    }
  }
  constexpr T com(int n, int k) const noexcept {
    if (n < k || n < 0 || k < 0) return 0;
    return fact_[n] * finv_[k] * finv_[n-k];
  }
  constexpr T fact(int n) const noexcept {
    if (n < 0) return 0;
    return fact_[n];
  }
  constexpr T inv(int n) const noexcept {
    if (n < 0) return 0;
    return inv_[n];
  }
  constexpr T finv(int n) const noexcept {
    if (n < 0) return 0;
    return finv_[n];
  }
};

const int mod=998244353;
const int nmax=55;
using mint=Fp<mod>;
BiCoef<mint> bc(nmax);
int n,k;
ll a[nmax][nmax];
bool ok;
mint ans1,ans2;

mint solve(){
  UnionFind u(n);
  rep(i,0,n){
    rep(j,i+1,n){
        ok=true;
        rep(m,0,n){
            if(a[m][i]+a[m][j]>k)ok=false;
        }
        if(ok)u.merge(i,j);
    }
  }
  mint ans=1;
  //get groups
  rep(i,0,n){
    if(u.root(i)==i)ans*=bc.fact(u.size(i));
  }
  return ans;
}

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n){
    rep(j,0,n){
      cin>>a[i][j];
    }
  }
  ans1=solve();
  rep(i,0,n){
    rep(j,i+1,n){
      swap(a[i][j],a[j][i]);
    }
  }
  ans2=solve();
  cout<<ans1*ans2<<endl;
  return 0;
}
