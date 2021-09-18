#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
using namespace std;


void solve(){
  int n;
  cin >> n;
  if(n == 2){
    cout << "-1" << endl;
    return;
  }
  for(int i = 1; i <= (n * n); i += n){
    cout << i << " ";
    for(int j = 1; j < n; ++j){
      int k = i + j * (n - 1);
      k = k > (n * n) ? k - (n * n) : k;
      cout << k << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}

