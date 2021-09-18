#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
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

int solve(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a==c&&b==d)return 0;
  if(
      ((a+b)==(c+d))|| // A
      ((a-b)==(c-d))|| // B
      ((abs(b-d)+abs(a-c))<=3) // C
  )return 1;
  // A -> B 
  if((a+b+c-d)%2==0&&(a+b-c+d)%2==0)return 2;
  // B -> A
  if((a-b+c+d)%2==0&&(-a+b+c+d)%2==0)return 2;
  // C -> B, B -> C
  if(abs((a-b)-(c-d))<=3)return 2;
  // C -> A, A -> C
  if(abs((a+b)-(c+d))<=3)return 2;
  // C -> C
  if((abs(b-d)+abs(a-c))<=6)return 2;
  return 3;
}

int main(){
  fastio;
  cout<<solve()<<endl;
  return 0;
}

