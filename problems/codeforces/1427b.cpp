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

const int N=2e5;
int t,n,k,ss,pr;
string s;
set<pi> st;

void solve(){
  cin>>n>>k>>s;
  ss=0;
  pr=0;
  rep(i,0,n)
    if(s[i]=='W'){
      pr=i;
      break;
    }
  if(pr>0)st.insert(mp(pr,0));
  rep(i,pr+1,n)
    if(s[i]=='W'){
      if(pr!=i-1){
        st.insert(mp(i-pr,pr));
        ++ss;
      }else{
        ss+=2;
      }
      pr=i;
    }
  st.insert(mp(n-pr,pr));
  auto it=st.begin();
  while(k>=0&&it!=st.end()){
    int a=it->se,b=it->se+it->fi,e=it->fi-1;
    if(k>=e){
      k-=e;
      ss+=e*2;
      ++ss;
    }else{
      k=0;
      ss+=(e-k)*2;
    }
    ++it;
  }
  cout<<ss<<endl;
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
