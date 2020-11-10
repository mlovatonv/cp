#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5;

string s;
int n,ans=nmax;

int getms(string &sc,char a,int t){
  int pos=-1;
  rrep(i,t,0)
    if(sc[i]==a){
      pos=i;
      break;
    }
  if(pos==-1)return nmax;
  int ms=0;
  if(t!=0&&pos==0&&sc[1]=='0'){
    int pos2=-1;
    rep(i,2,t)
      if(sc[i]!='0'){
        pos2=i;
        break;
      }
    if(pos2==-1)return nmax;
    while(pos2>1){
      swap(sc[pos2],sc[pos2-1]);
      --pos2;
      ++ms;
    }
  }
  while(pos<t){
    swap(sc[pos],sc[pos+1]);
    ++pos;
    ++ms;
  }
  return ms;
}

int getans(char a,char b){
  string sc=s;
  int ms=getms(sc,b,n-1);
  ms+=getms(sc,a,n-2);
  return ms;
}

int main(void){
  fastio;
  cin>>s;
  n=s.size();
  ans=min(ans,getans('0','0'));
  ans=min(ans,getans('2','5'));
  ans=min(ans,getans('5','0'));
  ans=min(ans,getans('7','5'));
  if(ans==nmax)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}
