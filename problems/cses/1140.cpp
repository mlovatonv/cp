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
const int nmax=4e5+1;

int n,x;
int a[nmax],b[nmax],p[nmax];
ll dp[nmax];
set<pi> s;
map<int,int> m;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>a[i]>>b[i]>>p[i];
    m[a[i]]=0;
    m[b[i]]=0;
  }
  x=m.size()+1;
  int j=0;
  for(auto &i:m){
    i.se=j++;
  }
  rep(i,0,n){
    a[i]=m[a[i]];
    b[i]=m[b[i]];
    s.emplace(b[i],i);
  }
  //cout<<"compressed:"<<endl;
  //rep(i,0,n){
  //  cout<<a[i]<<' ';
  //  auto it=s.lower_bound(mp(b[i],i));
  //  cout<<it->fi<<' '<<p[i]<<endl;
  //}
  rep(i,0,x){
    //cout<<"i="<<i<<endl;
    if(i)dp[i]=dp[i-1];
    auto it=s.lower_bound(mp(i-1,0));
    while(it!=s.end()&&it->fi==i-1){
      //cout<<"it->fi="<<it->fi<<" it->se="<<it->se<<endl;
      dp[i]=max(dp[i],dp[a[it->se]]+1LL*p[it->se]);
      ++it;
    }
    //cout<<"dp["<<i<<"]="<<dp[i]<<endl;
  }
  cout<<dp[x-1]<<endl;
  return 0;
}
