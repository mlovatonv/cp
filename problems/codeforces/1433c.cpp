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

const int nmax=3e5+50;
int t;
int n;
int maxa;
int a[nmax];

void solve(){
  cin>>n;
  a[0]=a[n+1]=1e9+1;
  rep(i,1,n+1)cin>>a[i];
  maxa=*max_element(a+1,a+n+1);
  //cout<<"maxa="<<maxa<<endl;
  rep(i,1,n+1){
    if(a[i]==maxa&&(a[i-1]<a[i]||a[i+1]<a[i])){
      cout<<i<<endl;
      return;
    } 
  }
  cout<<-1<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

