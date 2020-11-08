#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<ll,int>
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
ll sl,sr;

ll cost(){
  ll cl=m.fi*l.size()-sl,cr=sr-m.fi*r.size();
  return cl+cr;
}

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n)cin>>x[i];
  m=mp(x[0],0); 
  rep(i,1,k){
    if(x[i]<m.fi){
      l.insert({x[i],i});
      sl+=x[i];
    }else{
      r.insert({x[i],i});
      sr+=x[i];
    }
    if(r.size()<l.size()){
      auto le=(--l.end());
      r.insert(m);
      sr+=m.fi;
      m=*le;
      sl-=m.fi;
      l.erase(le);
    }elif(l.size()+1<r.size()){
      auto fe=r.begin();
      l.insert(m);
      sl+=m.fi;
      m=*fe;
      sr-=m.fi;
      r.erase(fe);
    }
  }
  cout<<cost()<<' ';
  rep(i,k,n){
    if(m.se==i-k){
      if(l.size()<r.size()){
        auto fe=r.begin();
        m=*fe;
        sr-=m.fi;
        r.erase(fe);
      }else{
        if(l.size()){
          auto le=(--l.end());
          m=*le;
          sl-=m.fi;
          l.erase(le);
        }else{
          m=mp(-1,-1);
        }
      }
    }else{
      if(l.erase({x[i-k],i-k}))sl-=x[i-k];
      elif(r.erase({x[i-k],i-k}))sr-=x[i-k];
    }
    if(m.fi==-1){
      m=mp(x[i],i);
    }elif(x[i]<m.fi){
      l.insert({x[i],i});
      sl+=x[i];
    }else{
      r.insert({x[i],i});
      sr+=x[i];
    }
    if(r.size()<l.size()){
      auto le=(--l.end());
      r.insert(m);
      sr+=m.fi;
      m=*le;
      sl-=m.fi;
      l.erase(le);
    }elif(l.size()+1<r.size()){
      auto fe=r.begin();
      l.insert(m);
      sl+=m.fi;
      m=*fe;
      sr-=m.fi;
      r.erase(fe);
    }
    cout<<cost()<<' ';
  }
  cout<<endl;
  return 0;
}
