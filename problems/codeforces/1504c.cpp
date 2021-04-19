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

void solve(){
  int n;
  string s,s1,s2;
  bool coin=true;
  cin>>n>>s;
  if(
      s[0]!='1'||s[n-1]!='1'||
      count_if(all(s),[](const char i){return i=='0';})%2
    ){
    cout<<"NO\n";
    return;
  }
  int k=count_if(all(s),[](const char i){return i=='1';});
  int j=0;
  rep(i,0,n)
    if(s[i]=='1'){
      s1+=j<k/2?'(':')';
      s2+=j<k/2?'(':')';
      ++j;
    }else{
      s1+=coin?'(':')';
      s2+=coin?')':'(';
      coin=!coin;
    }
  cout<<"YES"<<endl;
  cout<<s1<<endl;
  cout<<s2<<endl;
}

int main(){
  fastio;
  int t; 
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

