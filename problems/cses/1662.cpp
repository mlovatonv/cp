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

const int N=2e5+5;
int n;
ll x,cnt,a,s;
map<ll,int> m;

int main(void){
  fastio;
  cin>>n;
  m[0]=1;
  rep(i,0,n){
    cin>>a;
    s=(s+a%n+n)%n;
    if(m.find(s)!=m.end())cnt+=m[s];
    ++m[s];
  }
  cout<<cnt<<endl;
  return 0;
}
