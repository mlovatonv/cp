#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define em emplace
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
using namespace std;

const int N=1e3;
int n,minf,maxf;
string s;
set<pi> a,b,c;

int main(void){
  fastio;
  cin>>n;
  cin>>s;
  rep(i,0,n)a.em(s[i]-'0',i);
  cin>>s;
  rep(i,0,n){
    b.em(s[i]-'0',i);
    c.em(s[i]-'0',i);
  }
  for(auto& i:a){
    auto it=b.lower_bound(mp(i.fi,0));
    if(it==b.end())--it;
    minf+=it->fi<i.fi;
    b.erase(it);
  }
  for(auto& i:a){
    auto it=c.upper_bound(mp(i.fi,INT_MAX));
    if(it==c.end())--it;
    maxf+=i.fi<it->fi;
    c.erase(it);
  }
  cout<<minf<<endl<<maxf<<endl;
  return 0;
}

