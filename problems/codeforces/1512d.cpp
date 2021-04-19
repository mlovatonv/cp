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
using vi=vector<ll>;

int t;

void solve(){
  int n;
  ll s=0;
  cin>>n;
  n+=2;
  vi b(n);
  rep(i,0,n){
    cin>>b[i];
    s+=b[i];
  }
  sort(all(b));
  int xidx=-1,maxidx;
  rep(i,0,n){
    maxidx=(i==n-1)?n-2:n-1;
    if((s-b[i]-b[maxidx])==b[maxidx]){
      xidx=i;
      break;
    }
  }
  if(xidx!=-1){
    maxidx=(xidx==n-1)?n-2:n-1;
    rep(i,0,n){
      if(i!=xidx&&i!=maxidx)
        cout<<b[i]<<' ';
    }
    cout<<endl;
  }else{
    cout<<-1<<endl;
  }
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

