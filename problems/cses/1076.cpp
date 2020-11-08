#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5;
int n,k,x[N];
set<pi> l,r;
pi m;

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n)cin>>x[i];
  m=mp(x[0],0); 
  rep(i,1,k){
    if(x[i]<m.fi){
      l.insert({x[i],i}); 
    }else{
      r.insert({x[i],i});
    }
    if(r.size()<l.size()){
      auto le=(--l.end());
      r.insert(m);
      m=*le;
      l.erase(le);
    }elif(l.size()+1<r.size()){
      auto fe=r.begin();
      l.insert(m);
      m=*fe;
      r.erase(fe);
    }
  }
  cout<<m.fi<<' ';
  rep(i,k,n){
    if(m.se==i-k){
      if(l.size()<r.size()){
        auto fe=r.begin();
        m=*fe;
        r.erase(fe);
      }else{
        if(l.size()){
          auto le=(--l.end());
          m=*le;
          l.erase(le);
        }else{
          m=mp(-1,-1);
        }
      }
    }else{
      l.erase({x[i-k],i-k});
      r.erase({x[i-k],i-k});
    }
    if(m.fi==-1){
      m=mp(x[i],i);
    }elif(x[i]<m.fi){
      l.insert({x[i],i}); 
    }else{
      r.insert({x[i],i});
    }
    if(r.size()<l.size()){
      auto le=(--l.end());
      r.insert(m);
      m=*le;
      l.erase(le);
    }elif(l.size()+1<r.size()){
      auto fe=r.begin();
      l.insert(m);
      m=*fe;
      r.erase(fe);
    }
    cout<<m.fi<<' ';
  }
  cout<<endl;
  return 0;
}
