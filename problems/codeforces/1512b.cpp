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
  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,0,n)cin>>s[i];
  pair<int,int> p1={-1,-1},p2={-1,-1};
  rep(i,0,n){
    rep(j,0,n){
      if(s[i][j]=='*'){
        if(p1.fi==-1){
          p1={i,j};
        }else{
          p2={i,j};
          break;
        }
      }
    } 
  }
  if(p1.fi!=p2.fi&&p1.se!=p2.se){ // diagonal
    s[p1.fi][p2.se]='*';
    s[p2.fi][p1.se]='*';
  }elif(p1.fi!=p2.fi){ // vertical
    if(p1.se<n-1){
      s[p1.fi][p1.se+1]='*';
      s[p2.fi][p1.se+1]='*';    
    }else{
      s[p1.fi][p1.se-1]='*';
      s[p2.fi][p1.se-1]='*';  
    }
  }elif(p1.se!=p2.se){ // horizontal
    if(p1.fi<n-1){
      s[p1.fi+1][p1.se]='*';
      s[p1.fi+1][p2.se]='*';    
    }else{
      s[p1.fi-1][p1.se]='*';
      s[p1.fi-1][p2.se]='*';  
    }  
  }
  rep(i,0,n)cout<<s[i]<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

