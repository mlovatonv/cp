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
const int nmax=3e5;

int t,n;
string s;
int cr,c1r,c2r;

void build(){
  cr=0,c1r=0,c2r=0;
}

int main(void){
  fastio;
  cin>>t;
  rep(i,0,t){
    build();
    cin>>n;
    cin>>s;
    s+=s[0];
    rep(i,0,n){
      if(s[i]=='<'){
        ++c1r;
      }elif(s[i]=='>'){
        ++c2r;
      }
      if(s[i]=='-'||s[i+1]=='-'){
        ++cr;
      }
    };
    if(c1r==0||c2r==0)cout<<n<<endl;
    else cout<<cr<<endl;
  }
  return 0;
}
