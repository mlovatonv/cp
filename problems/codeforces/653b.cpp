#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=10;
int n,q;
vector<string> v[N];
char c;
string s;

ll search(int t,int x){
  if(x==0)return 1;
  ll ans=0;
  for(auto i:v[t])ans+=search(i[0]-'a',x-1);
  return ans;
}

int main(void){
  fastio;
  cin>>n>>q;
  rep(i,0,q){
    cin>>s>>c;
    v[c-'a'].pb(s);
  }
  cout<<search(0,n-1)<<endl;
  return 0;
}
