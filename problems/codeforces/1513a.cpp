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

int t;

void solve(){
  int n,k;
  cin>>n>>k;
  if(k>((n-1)/2)){
    cout<<-1<<endl;
    return; 
  }
  if(k==0){
    rep(i,1,n+1)cout<<i<<' ';
    cout<<endl;
    return;
  }
  int j=1;
  int jump=(n+1)/2;
  rep(i,0,k){
    cout<<j<<' '<<j+jump<<' ';
    ++j;
  }
  rep(i,j,1+jump)cout<<i<<' ';
  rep(i,j+jump,n+1)cout<<i<<' '; 
  cout<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

