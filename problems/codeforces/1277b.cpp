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

vector<pair<int,int>> fact(int n){ // O(logn);
  vector<pair<int,int>> pf;
  int count=0;
  while(!(n%2)){ // count the number of times 2 divides 
    n>>=1; // equivalent to n=n/2;
    count++;
  }
  if (count){ // if 2 divides it
    pf.pb({2,count});
    if(n)pf.pb({n,1});
  }else{
    pf.pb({n,1});
  }
  return pf;
}

int t;

void solve(){
  int n;
  cin>>n;
  set<int> s;
  rep(i,0,n-1){ // O(nlogn)
    int a;
    cin>>a;
    s.insert(a);
  }
  map<int,int> max_count_2;
  ret(i,s){
    vector<pair<int,int>> pf=fact(i); // O(nloga)
    int odd=0;
    int count_2=0;
    ret(j,pf){
      if(j.fi==2)count_2=j.se; 
      else odd+=j.fi*j.se;
    }
    dbg(i);
    dbg(odd);
    dbg(count_2);
    if(max_count_2.find(odd)==max_count_2.end()){ // not found
      max_count_2[odd]=count_2;
    }else{
      max_count_2[odd]=max(max_count_2[odd],count_2);
    }
  }
  dbg(max_count_2);
  int ans=0;
  ret(i,max_count_2)ans+=i.se;
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

