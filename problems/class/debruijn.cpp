#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define sz size()
#define be begin()
#define emp empty()
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=2e4;

unordered_map<int,char> adj[nmax];
int n;
stack<int> pc,pc_;
string ans;

void graph(){
  int nn=(1<<n-1)-1;
  rep(i,0,nn){
    int tran1=((i<<1)|1)&nn;
    int tran0=(i<<1)&nn;
    //cout<<i<<' '<<tran1<<' '<<tran0<<endl;
    adj[i][tran1]=1;
    adj[i][tran0]=0;
  }
}

void solve(){
  pc_.pu(0); // pila auxiliar
  while(!pc_.emp){
    int v=pc_.top();
    if(adj[v].sz==0){
      pc.pu(v);
      pc_.pop();
      continue;
    }
    int u=adj[v].be->fi;
    pc_.pu(u);
    adj[v].erase(u);
  }
}

int main(){
  fastio;
  cin>>n;
  if(n==1){
    cout<<"01";
    return 0;
  }
  graph();
  solve();
  int a=pc.top();
  rrep(i,n-2,0)cout<<(int)(a&(1<<i));
  pc.pop();
  while(!pc.emp){
    int b=pc.top();
    cout<<(int)(b&1);
    pc.pop();
  }
  return 0;
}
