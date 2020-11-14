#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

const int nmax=3e5+100;
using setit=set<int>::iterator;

int n,m;
int ans[nmax];
set<int> s;

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,1,n){
    s.insert(i); 
  }
  rep(i,1,m){
    int l,r,x;
    cin>>l>>r>>x;
    vector<setit> deleted;
    setit it=s.lower_bound(l);
    while(it!=s.end()&&(*it)<=r){
      if(*it!=x){
        ans[*it]=x;
        deleted.pb(it);
      }
      ++it;
    }
    for(auto j:deleted){
      s.erase(j);
    }
  }
  rep(i,1,n)cout<<ans[i]<<' ';
  return 0;
}
