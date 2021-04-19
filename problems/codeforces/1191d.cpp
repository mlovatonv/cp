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

const int nmax=1e5+10;
int a[nmax];
int n;

void solve(){
  cin>>n;
  rep(i,0,n)cin>>a[i];
  sort(a,a+n);
  ll s=a[0];
  int first=0;
  rep(i,1,n){
    s+=a[i];
    if(a[i]>a[i-1]){
      if(
          i-first>2||
          (i-first==2&&first&&a[first-1]==a[first]-1)
        ){
        cout<<"cslnb"<<endl;
        return;
      }
      first=i;
    }
  }
  if(s==0||s%2)cout<<"cslnb"<<endl;
  else cout<<"sjfnb"<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

