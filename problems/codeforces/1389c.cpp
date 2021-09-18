#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
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

vector<char> nums={'0','1','2','3','4','5','6','7','8','9'};

void solve(){
  string s;
  cin>>s;
  int n=len(s);
  // count worst case
  int ans=n-2;
  // count equal
  ret(i,nums){
    int cnt=count_if(all(s),[i](const char c)->bool{return c==i;});
    ans=min(ans,n-cnt);
  }
  // count pairs
  ret(i,nums){
    ret(j,nums){
      if(i!=j){
        int cnt=0;
        int k=0;
        int l=0;
        while(k<n){
          if(s[k]==i){
            l=k+1;
            while(l<n){
              if(s[l]==j){
                cnt+=2;
                break;
              }
              ++l;
            }
            k=l;
          }
          ++k;
        }
        ans=min(ans,n-cnt);
      }
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

