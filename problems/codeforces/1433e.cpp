#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ull=unsigned long long;
using vi=vector<int>;

ull n,ans;

ull comb(ull n,ull k) 
{
  if (k > n) return 0;
  if (k * 2 > n) k = n-k;
  if (k == 0) return 1;

  ull result = n;
  for(ull i = 2; i <= k; ++i ) { 
      result *= (n-i+1);
      result /= i;
  }   
  return result;
}

int main(){
  fastio;
  cin>>n;
  ans=comb(n,n/2);
  cout<<ans<<endl;
  return 0;
}

