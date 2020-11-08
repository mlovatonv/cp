#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
using namespace std;

int n;
string s1,s2,s3;
map<string,int> m;

void tl(string& s){
  for(auto& i:s)i=tolower(i);
}

int main(void){
  fastio;
  m["polycarp"]=1;
  cin>>n;
  rep(i,0,n){
    cin>>s1>>s2>>s3;
    tl(s1);
    tl(s3);
    m[s1]=m[s3]+1;
  }
  cout<<max_element(all(m),[](const auto& a,const auto& b)->bool{return a.se<b.se;})->se<<endl;
  return 0;
}
