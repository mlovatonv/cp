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
using ll=long long;
using vi=vector<int>;
const ll mod=1e9+7;

class Solution {
public:
    ll p(ll a,ll b,ll c,ll x){
        return ((x/a + x/b) - (x/c));
    } 
    
    int nthMagicalNumber(ll n,ll a,ll b) {
        ll l=0,r=1e14,m,c=lcm(a,b),t;
        rep(i,0,300){
            m=l+(r-l)/2LL;
            t=p(a,b,c,m);
            if (t < n)l=m;
            else if (t > n) r=m;
            else break;
        }
        return max(
            (((m/a)%mod)*(a%mod))%mod,
            (((m/b)%mod)*(b%mod))%mod
        );
    }
};
int main(){
  fastio;
  Solution sol;
  cout<<sol.nthMagicalNumber(3,8,3)<<endl;
  return 0;
}


