#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
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

const int nmax=65;
int n;
ll dpt[nmax],dpf[nmax];
string s;

int main(){
  fastio;
  dpt[0]=dpf[0]=1;
  cin>>n;
  rep(i,1,n){
    cin>>s;
    if(s=="AND"){
      dpt[i]=dpt[i-1];
      dpf[i]=dpt[i-1]+dpf[i-1]+dpf[i-1];
    }else{
      dpt[i]=dpt[i-1]+dpt[i-1]+dpf[i-1];
      dpf[i]=dpf[i-1];
    }
  }
  cout<<dpt[n]<<endl;
  return 0;
}

