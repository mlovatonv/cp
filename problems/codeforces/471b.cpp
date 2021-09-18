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
#define ret(i,c) for(auto &i:c)
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
  cin>>n;
  vector<pair<int,int>> v(n);
  map<int,int> m;
  rep(i,0,n-1){
    int h;
    cin>>h;
    v[i]={h,i+1};
    ++m[h];
  }
  sort(all(v));

  int cnt2=0,cnt3=0;
  ret(p,m){
    if(p.se>=2)++cnt2;
    if(p.se>=3)++cnt3;
  }

  dbg(cnt2);
  dbg(cnt3);

  if(cnt3>=1){
    cout<<"YES"<<endl;

    ret(p,v)cout<<p.se<<" ";
    cout<<endl;

    rep(i,0,n-3){
      if(v[i].fi==v[i+1].fi&&v[i+1].fi==v[i+2].fi){
        swap(v[i],v[i+1]);
        break; 
      }
    }

    ret(p,v)cout<<p.se<<" ";
    cout<<endl;

    rep(i,0,n-3){
      if(v[i].fi==v[i+1].fi&&v[i+1].fi==v[i+2].fi){
        swap(v[i],v[i+2]);
        break; 
      }
    }

    ret(p,v)cout<<p.se<<" ";
    cout<<endl;

  }elif(cnt2>=2){
    cout<<"YES"<<endl;

    ret(p,v)cout<<p.se<<" ";
    cout<<endl;

    int temp=0;
    rep(i,0,n-2){
      if(v[i].fi==v[i+1].fi){
        temp=i;
        swap(v[i],v[i+1]);
        break; 
      }
    }

    ret(p,v)cout<<p.se<<" ";
    cout<<endl;
    
    rep(i,0,n-2){
      if(i!=temp&&v[i].fi==v[i+1].fi){
        swap(v[i],v[i+1]);
        break; 
      }
    }

    ret(p,v)cout<<p.se<<" ";
    cout<<endl;

  }else{
    cout<<"NO"<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

