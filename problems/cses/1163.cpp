#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

int x,n,p,r,l;
set<int> s;
map<int,int> m;

int main(void){
  fastio;
  cin>>x>>n;
  s.insert(0);
  s.insert(x);
  m[x]=1;
  rep(i,0,n){
    cin>>p;
    auto it=s.lower_bound(p);
    r=*it;
    l=*(--it);
    --m[r-l];
    if(!m[r-l])m.erase(r-l);
    s.insert(p);
    ++m[r-p];
    ++m[p-l];
    cout<<(--m.end())->fi<<' ';
  }
  cout<<endl;
  return 0;
}
