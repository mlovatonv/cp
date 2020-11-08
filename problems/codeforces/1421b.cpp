#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=201;

int t,n,c;
pi ca[6];
char m[nmax][nmax];

bool inverse(char a,char b){
  c=0;
  if(m[0][1]!=a)ca[c++]=mp(1,2);
  if(m[1][0]!=a)ca[c++]=mp(2,1);
  if(m[0][2]!=b)ca[c++]=mp(1,3);
  if(m[1][1]!=b)ca[c++]=mp(2,2);
  if(m[2][0]!=b)ca[c++]=mp(3,1);
  if(c<=2){
    cout<<c<<endl;
    rep(i,0,c)cout<<ca[i].fi<<" "<<ca[i].se<<endl;
    return true;
  }
  return false;
}

void solve(){
  cin>>n;
  rep(i,0,n){
    cin>>m[i];
  }
  if(!inverse('1','0')&&!inverse('0','1'))cout<<0<<endl;
  //rep(i,0,n){
  //  rep(j,0,n){
  //    cout<<m[i][j]<<" ";
  //  }
  //  cout<<endl;
  //}
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
